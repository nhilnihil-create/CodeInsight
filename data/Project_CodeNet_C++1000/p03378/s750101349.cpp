#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,m,x;cin>>n>>m>>x;
  vector<int>a(m);
  rep(i,m)cin>>a[i];
  int l=0,r=0;
  rep(i,m){
    if(a[i]<x)l++;
    else r++;
  }
  int ans=min(l,r);
  cout<<ans<<endl;
}