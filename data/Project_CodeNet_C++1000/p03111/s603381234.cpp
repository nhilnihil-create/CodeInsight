#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define INF ((ll)1e18)
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, s, e) for (ll i = s, i##_len = (e); i < i##_len; ++i)
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

ll n, a, b, c, ans = INF;
vector<ll> l;

void dfs(vector<ll> &ls) {
  // lを0~4に分類するための数列を生成し、処理する

  if (ls.size() == n) {
    //処理
    vector<bool> f(3, false);
    REP(i, n) { f[ls[i]] = true; }
    if (!(f[0] && f[1] && f[2])) return;

    ll mp = ((ls.size() - count(ALL(ls), 3)) - 3) * 10;
    vector<ll> itg_l(3, 0);
    REP(i, 3) {
      REP(j, n) {
        if (ls[j] == i) itg_l[i] += l[j];
      }
    }

    vector<ll> t1 = {0, 1, 2};
    ll t2 = INF;
    do {
      t2 = min(
          abs(itg_l[t1[0]] - a) + abs(itg_l[t1[1]] - b) + abs(itg_l[t1[2]] - c),
          t2);
    } while (next_permutation(ALL(t1)));
    mp += t2;
    ans = min(ans, mp);
    return;
  }
  //数列生成
  for (ll i = 0; i < 4; i++) {
    ls.push_back(i);
    dfs(ls);
    ls.pop_back();
  }
}

int main() {
  cin >> n >> a >> b >> c;

  REP(i, n) {
    ll tmp;
    cin >> tmp;
    l.push_back(tmp);
  }
  vector<ll> ls;
  dfs(ls);
  cout << ans << endl;
  return 0;
}
