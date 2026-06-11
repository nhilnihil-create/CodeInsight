#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
  ll N,K;
  cin >> N >> K;
  ll res = 0;
  for(int b = N; b > K; b--){
    res += (N/b) * (b - K);
    ll mod = N % b;
    if(mod >= K){
      res += mod - K + 1;
    }
  }
  if(K == 0){
    cout << N * N << endl;
  }else{
    cout << res << endl;
  }
}
