#include <iostream>
#define llint long long
#define mod 1000000007

using namespace  std;

llint n, C;
llint dif[35][100005], sum[35][100005];
llint all[100005];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> C;
  llint s, t, c;
  for(int i = 1; i <= n; i++){
    cin >> s >> t >> c;
    dif[c][s-1]++, dif[c][t]--;
  }
  for(int i = 1; i <= C; i++){
    sum[i][0] = dif[i][0];
    for(int j = 1; j <= 100000; j++){
      sum[i][j] = sum[i][j-1] + dif[i][j];
      if(sum[i][j] > 0) all[j]++;
    }
  }

  /*for(int i = 1; i <= C; i++){
    for(int j = 1; j <= 10; j++){
      cout << sum[i][j];
    }
    cout << endl;
  }*/

  llint ans = 0;
  for(int i = 1; i <= 100000; i++){
    ans = max(ans, all[i]);
  }
  cout << ans << endl;

  return 0;
}
