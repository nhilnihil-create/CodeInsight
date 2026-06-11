#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int D, G;
  cin >> D >> G;
  vector<pair<int, int>> p(D);
  for (int i = 0; i < D; i++) {
    cin >> p[i].first >> p[i].second;
  }

  int ans{1000};
  for (int i = 0, n = 1 << D; i != n; ++i) {
    int maxr = -1, score = 0, solved = 0;
    for (int d = 0; d != D; ++d) {
      if (i & (1 << d)) {
        score += (d+1) * p[d].first * 100 + p[d].second;
        solved += p[d].first;
      } else {
        maxr = d;
      }
    }

    if (score < G) {
      if (maxr > -1 && (G - score < p[maxr].first * (maxr+1) * 100)) {
        solved += 1 + (G - score - 1) / ((maxr+1) * 100);
      } else {
        continue;
      }
    }
    
    ans = min(ans, solved);
  }
  cout << ans << endl;
}
