#include <iostream>
 
int main() {
  const static int NUM_OF_BOXES = 3;
  char boxes[3];
  std::cin >> boxes;
  int numOfBalls = 0;
  for (size_t i = 0U; i < NUM_OF_BOXES; ++i) {
    if (boxes[i] == '1') {
      numOfBalls++;
    }
  }
  std::cout << numOfBalls;
}