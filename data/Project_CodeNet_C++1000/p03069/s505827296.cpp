#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int cntb = 0;
  int cntw = 0;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    if (s[i] == '#') {
      if (i != 0 && s[i - 1] == '.') {
        v.push_back({cntb, cntw});
        cntb = 1;
        cntw = 0;
      } else {
        cntb++;
      }
    } else {
      cntw++;
    }
  }
  v.push_back({cntb, cntw});
  int m = v.size();
  int ans = 1e9;
  for (int k = 0; k <= m; k++) {
    int tmp = 0;
    for (int i = 0; i < k; i++) {
      tmp += v[i].first;
    }
    for (int i = k; i < m; i++) {
      tmp += v[i].second;
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
