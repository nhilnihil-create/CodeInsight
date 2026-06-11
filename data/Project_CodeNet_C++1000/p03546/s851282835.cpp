#include <bits/stdc++.h>
using namespace std; 
#define int int64_t
#define itn int
#define fi first
#define se second
#define mod 1000000007
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h,w;
  int c[10][10];
  int a[300][300],b;
  cin>>h>>w;
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      cin>>c[i][j];
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
    }
  }
  for(int k=0;k<10;k++){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++){
	c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
      }
    }
  }
  int ans=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a[i][j]!=-1) ans+=c[a[i][j]][1];
    }
  }
  cout<<ans<<"\n";
  return 0;
}
