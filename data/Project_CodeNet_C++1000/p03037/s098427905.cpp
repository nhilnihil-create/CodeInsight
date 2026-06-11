#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,m;cin>>n>>m;
  int L=0,R=1e9;
  rep(i,m){
    int l,r;cin>>l>>r;
    L=max(L,l);R=min(R,r);
  }
  int ans=max(R-L+1,0);
  cout<<ans<<endl;
}