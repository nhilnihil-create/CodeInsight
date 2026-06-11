#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> p(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &p[i].first);
    p[i].second = i;
  }
  sort(p.begin(), p.end());
  int t = 1, m = 0;
  for(int i = 1; i < n; i++) {
    if(p[i].second > p[i - 1].second)
      t++;
    else
      m = max(m, t), t = 1;
  }
  m = max(m, t);
  printf("%d\n", n - m);
}