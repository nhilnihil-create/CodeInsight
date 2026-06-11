#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll>v(n);
  rep(i,n)cin >> v[i];
  ll x = 0;
  for(ll i = 50; i >= 0; i--){
    ll ok = k - x;
    if(ok >= pow(2,i)){
      int cnt = 0;
      rep(j,n)if(!((v[j] >> i) & 1))cnt++;
      if(cnt >= (n + 1) / 2){
        x += pow(2,i);
      }
    }
  }
  ll ans = 0;
  rep(i,n)ans += (v[i] ^ x);
  cout << ans << endl;
  return 0;
}
