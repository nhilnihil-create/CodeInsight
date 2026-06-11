#include <iostream>
#include <vector>
int main(){
  long long N, K;
  std::cin >> N >> K;
  long long ans = 0;
  if(K % 2 != 0){
    long long t = N / K;
    ans = t*t*t;
  }
  else{
    long long t = N*2/K - N / K;
    long long s = N / K;
    ans = t*t*t + s*s*s;
  }
  std::cout << ans << std::endl;
}