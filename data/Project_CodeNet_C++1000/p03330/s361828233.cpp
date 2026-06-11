#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, C;
  cin>>n>>C;
  int d[C][C], c[n][n];
  for (int i=0; i<C; i++) {
    for (int j=0; j<C; j++) {
      cin>>d[i][j];
    }
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin>>c[i][j];
      --c[i][j];
    }
  }
  int cost[3][C];
  for (int i=0; i<3; i++) {
    for (int j=0; j<C; j++) {
      cost[i][j] = 0;
    }
  }
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      for (int k=0; k<C; k++) {
        cost[(i+j)%3][k] += d[c[i][j]][k];
      }
    }
  }
  int ans = 1e9;
  for (int c1=0; c1<C; c1++) {
    for (int c2=0; c2<C; c2++) {
      if (c1 == c2) {
        continue;
      }
      for (int c3=0; c3<C; c3++) {
        if (c2 == c3 || c3 == c1) {
          continue;
        }
        int sum_cost = 0;
        int new_c[3] = {c1, c2, c3};
        for (int i=0; i<3; i++) {
          sum_cost += cost[i][new_c[i]];
        }
        ans = min(sum_cost, ans);
      }
    }
  }
  cout<<ans<<endl;
}