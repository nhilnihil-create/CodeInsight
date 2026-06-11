#include<bits/stdc++.h>
using namespace std;

int dx[8]={-1,0,1,1,1,0,-1,-1};
int dy[8]={-1,-1,-1,0,1,1,1,0};

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> A(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> A.at(i).at(j);
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(A.at(i).at(j)=='#'){
        continue;
      }
      int count=0;
      for(int d=0;d<8;d++){
        int NX=dx[d]+i;
        int NY=dy[d]+j;
        if(0<=NX && NX<H && 0<=NY && NY<W && A.at(NX).at(NY)=='#'){
          count++;
        }
      }
      char D='0'+count;
      A.at(i).at(j)=D;
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout << A.at(i).at(j);
      if(j==W-1){
        cout << endl;
      }
    }
  }
}
  
          
      
  
  