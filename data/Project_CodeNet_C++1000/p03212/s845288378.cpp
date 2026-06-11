#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define INF 1000000000
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
#define __DEBUG__
#ifdef __DEBUG__
#define CH_P(a) cout <<"check_point("<<#a<<")" << "\n";
#define DEBUG(x) cout<<#x<<":"<<x<<"\n"
#define DEBUGS(v) cout << #v << ":";for(auto x:v){cout<<x<<" ";}cout<<"\n"
#endif
#ifndef __DEBUG__
#define CH_P(a) 
#define DEBUG(x) 
#define DEBUGS(v) 
#endif
/* clang-format on */

vector<ll> ans;
ll n;

void dfs(vector<ll> &a) {
  if (a.size() == n) {
    //処理

    vector<bool> f(3, false);
    REP(i, n) {
      if (a[i] == 3) f[0] = true;
      if (a[i] == 5) f[1] = true;
      if (a[i] == 7) f[2] = true;
    }
    if (!(f[0] && f[1] && f[2])) return;

    ll t = 0;
    REP(i, n) { t += pow(10, n - i - 1) * a[i]; }
    ans.push_back(t);
    // DEBUG(t);
    return;
  }
  vector<ll> t = {3, 5, 7};
  for (ll i = 0; i < 3; i++) {
    a.push_back(t[i]);
    dfs(a);
    a.pop_back();
  }
}

int main() {
  ll k;
  cin >> k;
  vector<ll> a;
  REP(i, 9) {
    n = i + 1;
    dfs(a);
  }
  sort(ALL(ans));
  ll cnt = 0;
  REP(i, ans.size()) {
    if (ans[i] <= k) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
