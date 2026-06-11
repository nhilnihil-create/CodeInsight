#include<bits/stdc++.h>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> A(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> A.at(i).at(j);
    }
  }
  bool b=false;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(A.at(i).at(j)=='.'){
        continue;
      }
      bool a=false;
      for(int d=0;d<4;d++){
        int NX=dx[d]+i;
        int NY=dy[d]+j;
        if(0<=NX && NX<H && 0<=NY && NY<W && A.at(NX).at(NY)=='#'){
          a=true;
          break;
        }
      }
      if(!a){
        b=true;
        break;
      }
    }
    if(b){
      break;
    }
  }
  if(b){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
}