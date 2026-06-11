#include <iostream>
int main(){
  int N, K;
  std::cin >> N >> K;
  if(N % K == 0) std::cout << 0 << std::endl;
  else std::cout << 1 << std::endl;
}