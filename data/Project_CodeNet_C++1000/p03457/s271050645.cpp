#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin>>n;
  int t[n+1],x[n+1],y[n+1]; t[0]=0,x[0]=0,y[0]=0;
  for(int i=1;i<n+1;i++) cin>>t[i]>>x[i]>>y[i];
  for(int i=0;i<n;i++){
    int d=abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
    int u=t[i+1]-t[i];
    if(d>u||(d<u&&(u-d)%2)){cout<<"No"; return 0;}
  }
  cout<<"Yes";
}