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

const int N = 21;
ll n, m, a[N], b, c;

int main() {
#ifdef LOCAL
  freopen("d.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  ll cur, ans = 0;
  cin >> n >> m >> c;
  for (int i = 0; i < m; i++) cin >> a[i];
  while (n--) {
    cur = 0;
    for (int i = 0; i < m; i++) {
      cin >> b;
      cur += b * a[i];
    }
    cur += c;
    ans += (cur > 0);
  }
  cout << ans << endl;
  return 0;
}