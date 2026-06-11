#include<bits/stdc++.h>

using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  
  long long s = 0;
  for(int b = K + 1; b <= N; b++){
    s += (N / b) * (b - K) + max(N - (N / b) * b - K + 1, 0);
    if(K == 0) s -= 1; // a > 0
  }
  
  cout << s << endl;
  
  return 0;
}