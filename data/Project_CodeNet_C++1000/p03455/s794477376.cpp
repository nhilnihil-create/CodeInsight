#include <bits/stdc++.h>

int main(){
  int a, b, c;
  std::cin >> a >> b;
  c = a*b;
  if(c%2==0)std::cout << "Even" << std::endl;
  else std::cout << "Odd" << std::endl;
  return 0;
}