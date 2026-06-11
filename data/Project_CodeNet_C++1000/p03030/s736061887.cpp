#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define forn(i, a, b) for (int i = a; i < b; ++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

bool cond(pair<pii, string> a, pair<pii, string> b) {
  if (a.S == b.S) return a.F.S > b.F.S;
  return a.S < b.S;
}

int main() {
#ifdef LOCAL
  freopen("j.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  int n, x;
  string s;
  cin >> n;
  vector<pair<pii, string>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> s >> x;
    v[i] = {{i + 1, x}, s};
  }
  sort(v.begin(), v.end(), cond);
  for (pair<pii, string> p : v) cout << p.F.F << endl;
  return 0;
}