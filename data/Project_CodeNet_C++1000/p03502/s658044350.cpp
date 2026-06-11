#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  std::cin >> N;
  
  int t = N, c = 0;
  while (true){
    c += t%10;
    t = t/10;
    if (t <= 0){
      break;
    }
  }
  
  if (N % c == 0){
    std::cout << "Yes" << std::endl;
  }
  else{
    std::cout << "No" << std::endl;
  }
}
