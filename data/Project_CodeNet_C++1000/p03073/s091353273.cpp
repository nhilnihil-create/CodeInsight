#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int a = 0, b = 0;
  for (int i = 0; i < s.size(); i++) {
    int c = s[i] - '0';
    if (c == i % 2) a++;
    if (c != i % 2) b++;
  }
  cout << min(a, b) << '\n';
}
