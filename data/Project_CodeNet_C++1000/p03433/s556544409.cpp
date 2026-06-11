#include <iostream>

int main(){
  int a, n;
  std::cin >> n;
  std::cin >> a;
  if (n%500<=a)
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;
  return 0;
}