#include<bits/stdc++.h>
using namespace std;

int D, G, p[10], c[10];

signed main() {
  cin >> D >> G; G/=100;
  for(int i=0; i<D; i++) cin >> p[i] >> c[i];
  for(int i=0; i<D; i++) c[i]/=100;

  int ans = 2e9;
  for (int bit = 0; bit < (1<<D); ++bit) {
    int score = 0;
    int problems = 0;
    for (int i = 0; i < D; ++i) if (bit & (1<<i)) {
      score += p[i] * (i+1) + c[i];
      problems += p[i];
    }
    if (score >= G) {
      ans = min(ans, problems);
      continue;
    }
    int res = G - score;
    for (int i = 0; i < D; ++i) if (!(bit & (1<<i))) {
      int r = (res + i) / (i+1);
      if(r > p[i]) continue;
      ans = min(ans, problems + r);
    }
  }
  cout << ans << endl;
}
