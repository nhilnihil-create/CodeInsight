#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

int n;
string s;

int main() {
  cin >> n >> s;
  map<pair<string, string>, int> a, b;
  range(i, 0, 1 << n) {
    string sa, sb;
    string ta, tb;
    range(j, 0, n) {
      if((i >> j) & 1) sa += s[j];
      else ta += s[j];
    }
    husk(j, n - 1, -1) {
      if((i >> j) & 1) sb += s[j + n];
      else tb += s[j + n];
    }
    b[make_pair(sb, tb)]++;
    a[make_pair(sa, ta)]++;
  }
  long long res = 0;
  for(auto it : a) {
    res += 1LL * it.second * b[it.first];
  }
  cout << res << endl;
  return 0;
}
