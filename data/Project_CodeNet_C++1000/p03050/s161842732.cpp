#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N,ans=0; cin >> N;
  if(N < 3){
    cout << "0";
    return 0;
  }
  ans += N-1;
  for(ll i = 1;i*i < N;i++){
    if(i == 1){
      continue;
    }
    if(N % i == 0 && i*(i+1) != N){
      ans += N/i;
      ans--;
    }
  }
  cout << ans;
}