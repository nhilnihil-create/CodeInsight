#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main() {
  int c[3][3],a[3],b[3];
  rep(i,3) rep(j,3) cin>>c[i][j];
  rep(i,c[0][0]+1){
    a[0]=i;
    rep(i,3) b[i]=c[0][i]-a[0];
    rep(i,2) a[i+1]=c[i+1][0]-b[0];
    rep(i,3) rep(j,3) if(c[i][j]!=a[i]+b[j]){cout<<"No"; return 0;}
  }
  cout<<"Yes";
}