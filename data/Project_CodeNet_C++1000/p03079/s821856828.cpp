#include <iostream>
int a, b, c;
int main(){
  std::cin >> a >> b >> c;
  if(a==b && b==c) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
}
