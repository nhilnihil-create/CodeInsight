#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int H,W;
  cin >> H >> W;

  vector<string> v(H), w;

  for(int i = 0; i < H; i++){
    cin >> v[i];
  }

  w = v;

  auto check = [&v, &H, &W](int x, int y){
    if(x < 0 || x >= H) return false;
    if(y < 0 || y >= W) return false;
    if(v.at(x).at(y) == '.') return false;
    return true;
  };

  int dx[8] = { 0, 1, 0,-1, 1, 1,-1,-1};
  int dy[8] = { 1, 0,-1, 0, 1,-1, 1,-1};

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(v.at(i).at(j) == '#'){
        continue;
      } 
      int sum = 0;
      for(int k  = 0; k < 8; k++){
        if(check(i + dx[k], j + dy[k])){
          sum++;
        }
      }
      char c = '0' + sum; 
      w.at(i).at(j) = c;
    }
  }

  for(int i = 0; i < H; i++){
    cout << w[i] << endl;
  }
}
