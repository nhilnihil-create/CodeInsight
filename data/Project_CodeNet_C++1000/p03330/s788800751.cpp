#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

signed main(){
  int n, c; cin >> n >> c;
  vector<vector<int> > data(3, vector<int> (c + 1)), table(c + 1, vector<int> (c + 1));
  for(int i = 1; i <= c; i++){
    for(int j = 1; j <= c; j++) scanf("%d", &table[i][j]);
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      int x; scanf("%d", &x);
      data[(i + j) % 3][x]++;
    }
  }

  int ans = INF;
  for(int c1 = 1; c1 <= c; c1++){
    for(int c2 = 1; c2 <= c; c2++){
      for(int c3 = 1; c3 <= c; c3++){
        if(c1 == c2 || c2 == c3 || c1 == c3) continue;
        int ans1 = 0;
        for(int i = 1; i <= c; i++) ans1 += table[i][c1] * data[0][i];
        for(int i = 1; i <= c; i++) ans1 += table[i][c2] * data[1][i];
        for(int i = 1; i <= c; i++) ans1 += table[i][c3] * data[2][i];
        ans = min(ans, ans1);
      }
    }
  }
  cout << ans << endl;
}
