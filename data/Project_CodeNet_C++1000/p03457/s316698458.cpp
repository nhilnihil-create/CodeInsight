#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,t[110000],x[110000],y[110000];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>t[i]>>x[i]>>y[i];
  }
  for(int i=1;i<=n;i++){
    if(t[i-1]<x[i-1]+y[i-1]) {cout<<"No"; return 0;}
    if(abs(t[i]-t[i-1])<abs(x[i]-x[i-1])+abs(y[i]-y[i-1])){cout<<"No"; return 0;}
  }
  for(int i=0;i<n;i++){
    if((t[i]%2==0 && (x[i]+y[i])%2==0) ||(t[i]%2!=0 && (x[i]+y[i])%2!=0)) continue;
    else {cout<<"No"; return 0;}
  }
  cout<<"Yes";
}
