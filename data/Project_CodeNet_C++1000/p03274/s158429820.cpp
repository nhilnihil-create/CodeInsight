#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define ALL(v) (v).begin(), (v).end()
//cout << std::fixed << std::setprecision(15) << y << endl;

int main(){
  ll N, K;  cin >> N >> K;
  VL x(N); 

  rep(i,0,N) cin >> x[i];
  ll ans = 1e18+5; ll tmp;
  rep(i,0,N){
    if(i > N-K) break;
    ll l, r;
    l = x[i]; r = x[i+K-1];
    tmp = min(abs(l) + abs(l-r), abs(r) + abs(l-r));
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}