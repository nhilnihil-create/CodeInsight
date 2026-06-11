#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

char grid[55][55];

int main(){
  int h,w;
  cin>>h>>w;
  for(int i=1; i<=h; i++){
    for(int j=1; j<=w; j++){
      cin>>grid[i][j];
    }
  }
  bool ans=1;
  for(int i=1; i<=h; i++){
    for(int j=1; j<=w; j++){
      if(grid[i][j]=='#'){
        if(grid[i+1][j]!='#'&&grid[i-1][j]!='#'&&grid[i][j+1]!='#'&&grid[i][j-1]!='#')ans=0;
      }
    }
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}


