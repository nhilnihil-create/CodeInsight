#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> s(m);
  for(int i = 0; i < m; i++) {
    int k; cin >> k;
    s[i].resize(k);
    for(int j = 0; j < k; j++) {
      cin >> s[i][j]; s[i][j]--;
    }
  }
  vector<int> p(m);
  for(int i = 0; i < m; i++) cin >> p[i];

  int ans = 0;
  for(int i = 0; i < (1<<n); i++) {
    bool ok = true;
    for(int j = 0; j < m; j++) {
      int cnt = 0;
      for(int v: s[j]) {
        if(i>>v & 1) cnt++;
      }
      if(cnt % 2 != p[j]) ok = false;
    }
    if(ok) ans++;
  }
  cout << ans << endl;

  return 0;
}
