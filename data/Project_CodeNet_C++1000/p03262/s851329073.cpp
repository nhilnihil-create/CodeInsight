#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define ALL(v) (v).begin(), (v).end()
//cout << std::fixed << std::setprecision(15) << y << endl;
ll INF=1e18+5;

ll gcd(ll a, ll b){
// 結合法則も成り立つ
  if(a < b) return gcd(b, a);
  ll r = a % b;
  while(r != 0){
      a = b;
      b = r;
      r = a % b;
  }
  return b;
}

int main(){
  ll N, X;  cin >> N >> X;
  VL x(N);  
  rep(i,0,N){
    cin >> x[i];
    x[i] = abs(X - x[i]);
  }
  sort(ALL(x));

  ll ans = INF;
  if(N == 1) ans = x[0];
  else{
    rep(i,1,N){
      ans = min(ans, gcd(x[i-1], x[i]));   
    }
  }
  cout << ans << endl;
  return 0;
}