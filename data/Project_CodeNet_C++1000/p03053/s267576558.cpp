#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;  cin >> h >> w;
  int field[1010][1010] = {0};
  queue<pair<int, int>> que;
  for(int i=0; i<h; i++){
    string s;  cin >> s;
    for(int j=0; j<w; j++)
      if(s[j] == '#')  que.push({i+1, j+1});
      else  field[i+1][j+1] = 1e9;
  }

  int d[] = {1, 0, -1, 0, 1}, ans = 0;
  while(!que.empty()){
    auto now = que.front();  que.pop();
    for(int i=0; i<4; i++)
      if(field[now.first][now.second] + 1 < field[now.first+d[i]][now.second+d[i+1]]){
	field[now.first+d[i]][now.second+d[i+1]] = field[now.first][now.second] + 1;
	ans = max(ans, field[now.first+d[i]][now.second+d[i+1]]);
	que.push({now.first+d[i], now.second+d[i+1]});
      }
  }
  
  cout << ans << endl;
  return 0;
}
