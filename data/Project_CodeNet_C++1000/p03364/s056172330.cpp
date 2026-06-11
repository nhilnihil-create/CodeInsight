#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
using namespace std;
typedef long long ll;
 
int len(int n, int a){
  if(a>=n){
    return a-n*(a/n);}
  else{ return a;}
}

int main(){
 int n;
  cin>>n;
  char grid[n][n];
  rep(i, n){
    rep(j, n){
      cin>>grid[i][j];
    }
  }
  
  int cnt=0;
  for(int b=0;b<n;b++){
    bool pos=true;
    for(int i=1;i<n;i++){
      for(int j=0;j<i;j++){
        if(grid[len(n, i+b)][j]!=grid[len(n, j+b)][i]){
          pos=false;
          break;}
      }
      if(!pos)
        break;
    }
    
    if(pos)
      cnt++;
  }
  
  cout<<cnt*n<<endl;
  
  
  
}