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
  int n, i;
  string a, b;
  double ans = 0, da, x;
  cin >> n;
  cout << fixed << setprecision(9);
  while (n--) {
    cin >> a >> b;
    da = i = x = 0;
    while (a[i] != '.' && i < SZ(a)) i++;
    da = stoi(a.substr(0, i));
    if (i != SZ(a)) {
      x = stoi(a.substr(i + 1, SZ(a)));
      da += (x / pow(10, SZ(a) - i - 1));
    }
    if (b == "BTC")
      ans += (da * 380000);
    else
      ans += da;
  }
  cout << ans << endl;
  return 0;
}