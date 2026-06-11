#include <bits/stdc++.h>
 
const int N = 505;
typedef std::pair<std::pair<int, int>, std::pair<int, int> > P;
 
int n, m, i, j, k, h, w;       
std::vector<P> ans;  
int a[N][N];
 
int main() {
  scanf("%d %d", &h, &w);
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      scanf("%d", a[i] + j);
    }
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j < w; j++) {
      if (a[i][j] & 1) {
        a[i][j]--;
        a[i][j + 1]++;
        ans.push_back(std::make_pair(std::make_pair(i, j), std::make_pair(i, j + 1)));
      }
    }
  }
  for (int i = 1; i < h; i++) {
    if (a[i][w] & 1) {
      a[i][w]--;    
      a[i + 1][w]++;
      ans.push_back(std::make_pair(std::make_pair(i, w), std::make_pair(i + 1, w)));
    }
  }
  printf("%d\n", ans.size());
  for (P v : ans) {
    printf("%d %d %d %d\n", v.first.first, v.first.second, v.second.first, v.second.second);
  }
  return 0;    
}