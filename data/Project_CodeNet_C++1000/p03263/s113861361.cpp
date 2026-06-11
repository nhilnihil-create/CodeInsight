#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int H, W;
  cin >> H >> W;
  vector<vector<int>> v(H,vector<int>(W,0));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> v.at(i).at(j);
    }
  }

  int x = 0; // たて
  int y = 0; // よこ
  int step = 0;
  int stock = 0;

  int nx;
  int ny;
  vector<pair<int,int>> before;
  vector<pair<int,int>> after;

  while(step < H*W-1){
    // 処理
    // cerr << x << " " << y << endl;
    // 奇数ならピック
    if(v.at(x).at(y) % 2 == 1 && stock == 0){
      stock++;
      //cout << x+1 << " " << y+1 << " "; 
      before.push_back(make_pair(x+1,y+1));
    } 

    // 次
    if(x % 2 == 0){
      if(y == W-1){
        nx = x + 1;
        ny = y;
      } else { 
        nx = x;
        ny = y + 1;
      }
    } else { 
      if(y == 0){
        nx = x + 1;
        ny = y;
      } else { 
        nx = x;
        ny = y - 1;
      }
    }

    x = nx;
    y = ny;
    if(stock > 0){
      // cout << nx+1 << " " << ny+1 << endl;
      after.push_back(make_pair(nx+1,ny+1));
      v.at(nx).at(ny) += 1;
      stock = 0;
    }
    step++;
  }

  cout << before.size() << endl;
  for(int i = 0; i < before.size(); i++){
    cout << before[i].first << " " << before[i].second << " ";
    cout << after[i].first << " "  << after[i].second << endl;
  }

}
