#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int N, M; cin >> N >> M;
  vector<int> L[N+1];

  for (int i = 0; i < M; i++) {
    int x, y, z; cin >> x >> y >> z;
    L[x].push_back(y);
    L[y].push_back(x);
  }

  int grp[N+1];
  int ans = 0;
  memset(grp, 0, sizeof(grp));
  vector<int> p, n;

  for (int i = 1; i <= N; i++) {
    if (grp[i] != 0) continue;
    
    ans++;
    n.push_back(i);
    grp[i] = ans;
    while (!n.empty()) {
      p = n;

      n.clear();
      for (auto it = p.begin(); it != p.end(); ++it) {
        
        for (auto jt = L[*it].begin(); jt != L[*it].end(); ++jt) {
          if (grp[*jt] != 0) continue;

          n.push_back(*jt);
          grp[*jt] = ans;

        }
      }
    }

  }

  cout << ans << endl;
  return 0;
}