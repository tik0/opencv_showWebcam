//============================================================================
// Name        : opencv_showWebcam.cpp
// Author      : Timo Korthals
// Version     :
// Copyright   : 
// Description : use openCV to display the webcam
//============================================================================

#include <iostream>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;

const int KEY_ESC = 27;
const int DELAY = 30;

const string WIN_NAME = "Camera View";

int main() {

  // Creating the cam object
  cv::VideoCapture cam;
  // Open the device /dev/video0
  cam.open(0);
  // Allocate a frame object to store the picture
  cv::Mat frame;

  // Read the key
  int key = cv::waitKey(DELAY);

  // Process the cam as long as it is open
  for (; cam.isOpened();) {

    // Save the actual picture to the frame object
    cam >> frame;

    // Show the picture
    cv::imshow(WIN_NAME, frame);

    // Read a keystroke
    key = cv::waitKey(DELAY);

    // If the keystroke was ESC, then break
    if (KEY_ESC == key)
      break;
  }

  // Free the cam
  cam.release();

  return 0;
}
