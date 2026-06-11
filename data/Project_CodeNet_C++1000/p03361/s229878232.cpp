#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w; cin >> h >> w;
  vector<vector<char>> map(h, vector<char>(w));
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> map.at(i).at(j);
    }
  }
  vector<int> dx = {-1, 0, 1, 0};
  vector<int> dy = {0, -1, 0, 1};
  bool ok;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(map[i][j] == '#'){
        ok = false;
      	for(int k = 0; k < 4; k++){
       	 if(i + dx[k] >= 0 && i + dx[k] < h && j + dy[k] >= 0 && j + dy[k] < w){
           if(map[i+dx[k]][j+dy[k]] == '#') ok = true;
         }
        }
      }
      if(!ok) break;
    }
    if(!ok) break;
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}