#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,m;cin>>n>>m;
  vector<vector<int>> s(m);
  rep(i,m){
    int k;cin>>k;
    rep(j,k){
      int a;cin>>a;
      a--;
      s[i].push_back(a);
    }
  }
  vector<int> p(m);
  rep(i,m)cin>>p[i];
  int ans=0;
  rep(bit,1<<n){
    bool ok=true;
    rep(i,m){
      int cnt=0;
      for(auto x:s[i]){
        if(bit&(1<<x))cnt++;
      }
      if(cnt%2!=p[i])ok=false;
    }
    if(ok)ans++;
  }
  cout<<ans<<endl;
}