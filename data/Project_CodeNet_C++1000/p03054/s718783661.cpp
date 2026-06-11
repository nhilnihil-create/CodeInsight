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


bool check_1d(V &a, V &b, int m, int s) {
  reverse(all(a));
  reverse(all(b));
  int n = a.size();
  int l = 0, r = m-1;
  rep(i, n) {
    if (b[i] ==  1) l = max(l-1, 0);
    if (b[i] == -1) r = min(r+1, m-1);
    if (a[i] ==  1) r--;
    if (a[i] == -1) l++;
    if (l > r) return false;
  }
  if (s < l || s > r) return false;
  return true;
}


int main() {
  int H, W, N; cin >> H >> W >> N;
  int r, c; cin >> r >> c;
  r--; c--;
  string s, t; cin >> s >> t;

  V a(N), b(N);
  rep(i, N) {
    if (s[i] == 'D') a[i] = 1;
    if (s[i] == 'U') a[i] = -1;
    if (t[i] == 'D') b[i] = 1;
    if (t[i] == 'U') b[i] = -1;
  }
  bool ans1 = check_1d(a, b, H, r);

  a = V(N); b = V(N);
  rep(i, N) {
    if (s[i] == 'R') a[i] = 1;
    if (s[i] == 'L') a[i] = -1;
    if (t[i] == 'R') b[i] = 1;
    if (t[i] == 'L') b[i] = -1;
  }
  bool ans2 = check_1d(a, b, W, c);

  if (ans1 && ans2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
