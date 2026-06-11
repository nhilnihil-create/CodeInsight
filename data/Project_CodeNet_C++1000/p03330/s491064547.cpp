#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define chmin(i, j) i = min(i, j);
#define chmax(i, j) i = max(i, j);
int main() {
  int n, C;
  cin >> n >> C;
  vector<vector<int>> d(C, vector<int>(C));
  for(int i=0;i<C;i++) for(int j=0;j<C;j++) cin >> d[i][j];
  vector<vector<int>> c(n, vector<int>(n));
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
    cin >> c[i][j];
    c[i][j]--;
  }
  vector<vector<int>> modColor(3, vector<int>(C));
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
    int r = (i + j) % 3;
    modColor[r][c[i][j]]++;
  }
  vector<vector<long long>> cost(3, vector<long long>(C));
  for(int i=0;i<3;i++) {
    for(int j=0;j<C;j++) {
      long long total = 0;
      for(int k=0;k<C;k++) {
        total += d[k][j] * modColor[i][k];
      }
      cost[i][j] = total;
    }
  }
  long long ans = 100100100100100100;
  for(int i=0;i<C;i++) {
    for(int j=i+1;j<C;j++) {
      for(int k=j+1;k<C;k++) {
        vector<int> v({i, j, k});
        sort(v.begin(), v.end());
        do {
          chmin(ans, cost[0][v[0]] + cost[1][v[1]] + cost[2][v[2]]);
        } while(next_permutation(v.begin(), v.end()));
      }
    }
  }
  cout << ans << endl;
}
