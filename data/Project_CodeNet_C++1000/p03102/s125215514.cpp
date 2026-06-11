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
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
  ll n, m, c;
  cin >> n >> m >> c;
  ll ans = 0;
  VL b(m);
  rep(i, 0, m) cin >> b[i];
  rep(i, 0, n){
    ll cur = c;
    rep(j, 0, m){
      ll a;
      cin >> a;
      cur += a * b[j];
    }
    if(cur > 0) ans++;
  }
  cout << ans << endl;
    return 0;
}
