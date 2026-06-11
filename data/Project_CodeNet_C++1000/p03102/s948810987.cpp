#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main() {
  int n,m,c,t,cnt=0; cin>>n>>m>>c;
  int b[m];
  rep(i,m) cin>>b[i];
  rep(i,n){
    int s=0;
    rep(j,m) cin>>t,s+=t*b[j];
    if(s+c>0) cnt++;
  }
  cout<<cnt;
}
