#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i=(int)s;i<(int)n;i++)
int main() {
  int n,m=0; cin>>n;
  int a[n],b[n]; rep(i,0,n) cin>>a[i]; rep(i,0,n) cin>>b[i];
  rep(d,0,n){
    int s=0;
    rep(i,0,d+1) s+=a[i];
    rep(i,d,n) s+=b[i];
    m=max(s,m);
  }
  cout<<m;
}