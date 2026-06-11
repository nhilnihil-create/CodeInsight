#include <iostream>
#include <vector>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> s(H, vector<char>(W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> s.at(i).at(j);
    }
  }
  bool can = true;
  const vector<int> di = {-1,0,1,0};
  const vector<int> dj = {0,-1,0,1};
  for(int i=0; i<H && can; i++){
    for(int j=0; j<W && can; j++){
      if(s.at(i).at(j)=='#'){
        bool can_ij = false;
        for(int k=0; k<4; k++){
          int ni = i+di.at(k);
          int nj = j+dj.at(k);
          if(ni<0 || ni>=H) continue;
          if(nj<0 || nj>=W) continue;
          if(s.at(ni).at(nj)=='#'){
            can_ij = true;
          }
        }
        if(!can_ij){
          can = false;
          break;
        }
      }
    }
  }
  if(can){
    cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}