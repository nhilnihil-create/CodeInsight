#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}


int main() {
  ll n, k; cin >> n >> k;
  k++;
  Vll a(n); 
  rep(i, n) cin >> a[i];
  const int m = 42;

  VVll cnt(m, Vll(2));
  rep(i, m) rep(j, n) {
    if (a[j] % 2 == 0) ++cnt[i][0];
    if (a[j] % 2 == 1) ++cnt[i][1];
    a[j] /= 2;
  }

  Vll score(m+1);
  rep(i, m) {
    score[i+1] += score[i] + (max(cnt[i][0], cnt[i][1])) * (1ll<<i);
  }

  ll d = 1ll<<m;
  ll scr_now = 0;
  ll ans = 0;
  for (int i = m-1; i >= 0; --i) {
    int x = (k / (1ll<<i)) % 2;
    if (x == 1) {
      chmax(ans, scr_now + cnt[i][1] * (1ll<<i) + score[i]);
    }
    scr_now += cnt[i][1-x] * (1ll<<i);
  }
  cout << ans << endl;
  return 0;
}
