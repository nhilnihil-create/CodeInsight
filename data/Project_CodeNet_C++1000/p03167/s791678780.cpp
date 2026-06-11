#include<bits/stdc++.h>

using namespace std;



int main(){
  int H,W;

  cin>>H>>W;
  char grid[H][W];
  long long paths[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>grid[i][j];
      paths[i][j] = 0;
    }
  }

  paths[0][0] = 1;
  long long mod = 1e9 + 7;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(grid[i][j] == '.'){
        if(i-1>=0)
        paths[i][j] = (paths[i][j] + paths[i-1][j]%mod)%mod;
        if(j-1>=0)
        paths[i][j] = (paths[i][j] +paths[i][j-1]%mod)%mod;
      }
      else{
        paths[i][j] = (long long)0;
      }
    }
  }

  cout<<((int)(paths[H-1][W-1]%mod));

  return 0;
}
