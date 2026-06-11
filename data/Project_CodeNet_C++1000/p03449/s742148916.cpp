#include <bits/stdc++.h>
using namespace std;

/*
2行で移動方向は右か下のみ, つまり1行目の何列目まで進んでから下に進むかのみ考えれば良い.
各行の累積和を予め求めておけば, ある経路を辿ったときのアメの合計は,
1行目i列目までの1行目の累積和 
+ (終点(2行目n列目)までの2行目の累積和 
- 2行目i-1列目までの2行目の累積和)
で求まる.
*/

int main() {
  int n;
  cin >> n;
  vector<vector<int>> table(2, vector<int>(n+1));
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> table[i][j];
      table[i][j] += table[i][j-1];  // 現在の行のj列目までの累積和
    }
  }
  
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, table[0][i] + table[1][n] - table[1][i-1]);
  }  
  
  cout << ans << endl;
}