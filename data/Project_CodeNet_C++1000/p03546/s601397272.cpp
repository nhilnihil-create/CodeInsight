#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int c[10][10];
int memo[11];

int dfs(int ini, int now, int sum){
  if(now == 1){
    memo[ini] = min(memo[ini], sum);
    return 0;
  }

  if(memo[ini] <= sum) return 0;

  for(int nex = 0; nex < 10; nex++){
    if(nex==now) continue;
    dfs(ini, nex, sum + c[now][nex]);
    // dfs(ini, nex, sum);
  }

  return 0;
}

int main(){
  int h, w;
  cin >> h >> w;
  const int max_h = 200;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cin >> c[i][j];
    }
  }
  int a[max_h + 1][max_h + 1];
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> a[i][j];
    }
  }

  for(int i = 0; i < 10; i++) memo[i] = INF;
  for(int i = 0; i < 10; i++){
    dfs(i, i, 0);
  }

  int ans = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(a[i][j] == -1) continue;
      ans += memo[a[i][j]];
    }
  }

  cout << ans << endl;

  return 0;
}