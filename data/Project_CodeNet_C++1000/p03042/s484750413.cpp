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
  freopen("h.txt", "r", stdin);
// freopen("main.txt", "w", stdout);
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
  ios::sync_with_stdio(0);
  cin.tie(0);
#define endl '\n'
#define dbg(...) 18
#endif
  string s;
  cin >> s;
  bool a, b;
  a = (stoi(s.substr(0, 2)) <= 12 && stoi(s.substr(0, 2)) > 0);
  b = (stoi(s.substr(2, 4)) <= 12 && stoi(s.substr(2, 4)) > 0);
  if (a && b)
    cout << "AMBIGUOUS" << endl;
  else if (b)
    cout << "YYMM" << endl;
  else if (a)
    cout << "MMYY" << endl;
  else
    cout << "NA" << endl;
  return 0;
}