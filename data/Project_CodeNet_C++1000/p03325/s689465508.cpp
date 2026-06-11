#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
//cout << std::fixed << std::setprecision(15) << y << endl;

vector<pair<ll,ll>> prime_factorize(ll N){
  vector<pair<ll,ll>> ret;
  for(ll a = 2; a * a <= N; a++){
    if(N % a != 0) continue;
    ll ex = 0;
    while(N % a == 0){
      ex++;
      N /= a;
    }
    ret.push_back({a, ex});
  }
  if(N != 1) ret.push_back({N, 1});
  return ret;
}
 
int main(){
  ll n;  cin >> n;
  VL a(n); rep(i,0,n) cin >> a[i];
  ll ans = 0;
  rep(i,0,n){
    auto v = prime_factorize(a[i]);
    for(auto e : v){
      if(e.first == 2){ans += e.second; break;}
    }
  }
  cout << ans << endl;
  return 0;
}