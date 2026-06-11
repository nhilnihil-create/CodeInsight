#include<bits/stdc++.h>
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using namespace std;

int main(){
  int n;cin>>n;
  int t,x,y,T=0,X=0,Y=0;
  string ans="Yes";
  rep(i,n){
    cin>>t>>x>>y;
    T=t-T;
    X=abs(X-x);
    Y=abs(Y-y);
    if(X+Y>T||((X+Y)%2!=T%2))ans="No";
  }
  cout<<ans;
}