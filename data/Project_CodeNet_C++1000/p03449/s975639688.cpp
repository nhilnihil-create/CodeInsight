#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

int main(){
  ll N; cin >> N;
  VL a(N);
  VL b(N);
  rep(i,0,N) cin >> a[i];
  rep(i,0,N) cin >> b[i];
  
  ll ans = 0;
  ll tmp = 0;
  rep(i,0,N){
    tmp = 0;
    rep(j,0,i+1){
      tmp += a[j];
    }
    rep(k,i,N){
      tmp += b[k];
    }
    ans = max(tmp, ans);
  }
  cout << ans << endl;
  return 0;
}