#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, o = 0;
  scanf("%d %d", &n, &k);
  vector<int> v(n);
  for(int i = 0; i < n; i++) scanf("%d", &v[i]);
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      int s = k - i - j, t = 0;
      if(i + j > n || s < 0) continue;
      vector<int> h;
      for(int r = 0; r < i; r++) h.push_back(v[r]), t += v[r];
      for(int l = 0; l < j; l++) h.push_back(v[n - 1 - l]), t += v[n - 1 - l];
      sort(h.begin(), h.end());
      int m = t;
      for(int l = 0; l < min(s, i + j); l++) m = max(m, t -= h[l]);
      o = max(o, m);
    }
  }
  printf("%d\n", o);
}