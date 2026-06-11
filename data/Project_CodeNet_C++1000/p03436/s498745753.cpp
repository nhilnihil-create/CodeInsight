#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w, white = 0;  cin >> h >> w;
  char s[55][55];
  for(int i=1; i<=h; i++)
    for(int j=1; j<=w; j++){
      cin >> s[i][j];
      if(s[i][j] == '.')  white++;
    }
  
  int cost[55][55] = {0}, d[] = {1, 0, -1, 0, 1};
  cost[1][1] = 1;
  queue<pair<int, int>> que;
  que.push({1, 1});
  while(!que.empty()){
    int nowh = que.front().first, noww = que.front().second;
    que.pop();
    for(int i=0; i<4; i++){
      int nexh = nowh + d[i], nexw = noww + d[i+1];
      if(s[nexh][nexw]=='.' && !cost[nexh][nexw]){
	que.push({nexh, nexw});
	cost[nexh][nexw] = cost[nowh][noww] + 1;
      }
    }
  }

  int ans =  white - cost[h][w];
  if(!cost[h][w])  ans = -1;

  cout << ans << endl;

  return 0;
}
