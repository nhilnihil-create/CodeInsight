#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  std::cin >> N >> K;
  
  int now = 1;
  int i;
  for (i = 0; i < N; i++){
    if (now <= K){
      now *= 2;
    }
    else{
      now += K;
    }
  }
  std::cout << now << std::endl;
}
