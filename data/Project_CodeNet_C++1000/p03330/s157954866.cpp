#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int n,c,i,j,k,x,y,d[33][33],g[505][505],t[3][33]={};
  
  cin >> n >> c;
  for (i=1;i<=c;i++) for (j=1;j<=c;j++){
    cin >> d[i][j];
  }
  for (i=0;i<n;i++) for (j=0;j<n;j++){
    cin >> g[i][j];
  }
  
  for (i=0;i<n;i++) for (j=0;j<n;j++){
    for (k=1;k<=c;k++){
      t[(i+j)%3][k]+=d[g[i][j]][k];
    }
  }
  
  int ans=1e9,s;
  for (i=1;i<=c;i++) for (j=1;j<=c;j++){
    if (i==j) continue;
    
    for (k=1;k<=c;k++){
      if (i==k || j==k) continue;
      s=t[0][i]+t[1][j]+t[2][k];
      ans=min(ans,s);
      
    }
    
  }
  
  cout << ans << endl;
  
  return 0;
}