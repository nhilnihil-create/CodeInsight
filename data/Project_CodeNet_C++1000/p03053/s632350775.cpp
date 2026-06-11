#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;  cin >> h >> w;
  vector<vector<int>> field(h+2, vector<int>(w+2, 0));
  queue<pair<int, int>> que;
  for(int i=0; i<h; i++){
    string s;  cin >> s;
    for(int j=0; j<w; j++)
      if(s[j] == '.')  field[i+1][j+1] = -1;
      else  que.push({i+1, j+1});
  } 

  while(!que.empty()){
    auto now = que.front();  que.pop();
    for(int i=-1; i<=1; i++)
      for(int j=-1; j<=1; j++){
        if(abs(i)+abs(j) == 2 || (i == 0 && j == 0))  continue;
        if(field[now.first+i][now.second+j] < 0){
          field[now.first+i][now.second+j] = field[now.first][now.second] + 1;
          que.push({now.first+i, now.second+j});
        }
      }
  }

  int ans = 0;
  for(int i=1; i<=h; i++){
    for(int j=1; j<=w; j++)
      ans = max(ans, field[i][j]);
  }
 
  cout << ans << endl;

  return 0;
}
