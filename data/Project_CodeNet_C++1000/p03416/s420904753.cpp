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

bool f(string s) {
  for (int i = 0, j = SZ(s) - 1; i < j; i++, j--)
    if (s[i] != s[j]) return false;
  return true;
}

int main() {
#ifdef LOCAL
  freopen("h.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  int a, b, c = 0;
  string s;
  cin >> a >> b;
  while (a <= b) {
    s = to_string(a);
    c += f(s);
    a++;
  }
  cout << c << endl;
  return 0;
}