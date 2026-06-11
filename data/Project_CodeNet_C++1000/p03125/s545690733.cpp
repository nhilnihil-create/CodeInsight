#include <iostream>

int main()
{
  int A, B;
  std::cin >> A >> B;

  int ret = B - A;
  if(B % A == 0) {
    ret = A + B;
  }

  std::cout << ret << std::endl;
  return 0;
}
