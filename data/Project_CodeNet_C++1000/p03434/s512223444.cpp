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
  freopen("f.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.rbegin(), v.rend());
  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1)
      b += v[i];
    else
      a += v[i];
  }
  cout << (a - b) << endl;
  return 0;
}