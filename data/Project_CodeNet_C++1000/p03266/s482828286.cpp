#include<bits/stdc++.h>

using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<long> m(K, 0);
  
  for(int i = 1; i <= N; i++){
    m[i%K] += 1;
  }
  
  long ans = 0;
  long tmp;
  for(int i = 1; i <= N; i++){
    tmp = (K - i%K) % K;
    if( (tmp + tmp) % K == 0){
      ans += m[tmp] * m[tmp];
    }
  }
  
  cout << ans << endl;
}