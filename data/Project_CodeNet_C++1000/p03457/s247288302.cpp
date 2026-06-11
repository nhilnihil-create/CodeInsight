#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int t[n],x[n],y[n];
  rep(i,0,n) cin>>t[i]>>x[i]>>y[i];
  int cx=0;
  int cy=0;
  int ct=0;
  bool p=true;
  rep(i,0,n){
    if(abs(cx-x[i])+abs(cy-y[i])>t[i]-ct) p=false;
    else if((t[i]-ct-abs(cx-x[i])-abs(cy-y[i]))%2!=0) p=false;
    cx=x[i];
    cy=y[i];
    ct=t[i];
  }
  if(p) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}