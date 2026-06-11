#include <bits/stdc++.h>
using namespace std;


int main() {
  int H,W;
  cin>>H>>W;
  
  vector<vector<char>> grid(H, vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>grid.at(i).at(j);
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(grid.at(i).at(j)=='.') continue;
      else{
        if(j>=1&&grid.at(i).at(j-1)=='#') continue;
        if(j<=W-2&&grid.at(i).at(j+1)=='#') continue;
        if(i>=1&&grid.at(i-1).at(j)=='#') continue;
        if(i<=H-2&&grid.at(i+1).at(j)=='#') continue;
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
    
  
}