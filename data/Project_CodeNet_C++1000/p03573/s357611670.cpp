#include<iostream>

int main(){
  int a, b, c, x;
  std::cin >> a >> b >> c;
  if(a == b)
    x = c;
  else if(b == c)
    x = a;
  else
    x = b;
  std::cout << x << std::endl;
  return 0;
}
