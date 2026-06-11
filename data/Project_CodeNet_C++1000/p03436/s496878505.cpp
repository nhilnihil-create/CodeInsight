#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int main(){
  
  int H, W, i, j, d = 0;
  vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
  cin >> H >> W;
  vector<vector<char>> s(H, vector<char>(W));
  vector<vector<int>> checked(H, vector<int>(W, 0));
  
  for (i = 0; i < H; i++){
    for (j = 0; j < W; j++){
      cin >> s.at(i).at(j);
      if(s.at(i).at(j) == '#') d++;
    }
  }
  
  P pos = P(0, 0);
  queue<P> quepos;
  quepos.push(pos);
  
  while(quepos.size()){
    
    pos = quepos.front(); quepos.pop();
    for(i = 0; i < 4; i++){
      
      int x = pos.first + dx.at(i), y = pos.second + dy.at(i);
      if(x >= 0 && x < W && y >= 0 && y < H && s.at(y).at(x) == '.' && checked.at(y).at(x) == 0){

        checked.at(y).at(x) = checked.at(pos.second).at(pos.first) + 1;
        quepos.push(P(x, y));
        if(y == H - 1 && x == W - 1){
          cout << H * W - d - checked.at(y).at(x) - 1 << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 << endl;
}