#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<int> b(n);
  range(i, 0, n) {
    cin >> b[i];
    b[i] -= i;
  }
  long long res = 0;
  map<int, int> pos;
  map<int, int> p;
  range(i, 0, n) {
    if(b[i] < -i || b[i] > 0) {
      cout << -1;
      return 0;
    }
    pos[-b[i]] = i;
    if(p.find(-b[i]) == p.end()) p[-b[i]] = i;
  }
  int cur = -1;
  for(auto it : pos) {
    if(p[it.first] < cur) {
      cout << -1;
      return 0;
    }
    cur = max(cur, it.second);
    res += it.second - it.first;
  }
  cout << res;
  return 0;
}
