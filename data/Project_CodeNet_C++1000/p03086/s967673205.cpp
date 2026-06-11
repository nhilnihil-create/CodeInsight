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
  freopen("e.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  string s;
  bool cond;
  cin >> s;
  int ans = 0, cur = 0;
  char c[] = {'A', 'C', 'G', 'T'};
  for (int i = 0; i < SZ(s); i++) {
    cond = false;
    for (int j = 0; j < 4; j++) cond |= (s[i] == c[j]);
    if (cond)
      cur++;
    else {
      ans = max(ans, cur);
      cur = 0;
    }
  }
  cout << max(ans, cur) << endl;
  return 0;
}