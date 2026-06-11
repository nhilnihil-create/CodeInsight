#include <iostream>
int main(void)
{
  int inputNum1, inputNum2;
  std::cin >> inputNum1 >> inputNum2;
  int total = inputNum1 * inputNum2;
  if(total % 2 == 1) {
    std::cout << "Odd" << std::endl;
  }
  else {
    std::cout << "Even" << std::endl;
  }
  return 0;
}