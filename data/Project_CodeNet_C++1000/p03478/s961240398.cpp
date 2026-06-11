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

int n, a, b;

int f(int m) {
  int r = 0;
  while (m != 0) {
    r = r + m % 10;
    m = m / 10;
  }
  return r;
}

int main() {
#ifdef LOCAL
  freopen("b.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  cin >> n >> a >> b;
  int ans = 0, sum;
  for (int i = 1; i <= n; i++) {
    sum = f(i);
    if (sum >= a && sum <= b) ans += i;
  }
  cout << ans << endl;
  return 0;
}