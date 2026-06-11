#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> k(m);
  vector<int> p(m);
  rep(i,m){
    int K; cin>>K;
    rep(j,K){
      int s; cin>>s;
      s--;
      k[i].push_back(s);
    }
  }
  rep(i,m){
    cin>>p[i];
  }
  int ans=0;
  for(int i = 0; i < (1<<n); i++){
    bool ok=1;
    rep(j,m){
      int cnt=0;
      for(auto x : k[j]){
        if(i>>x&1) cnt++;
      }
      if(cnt%2!=p[j])ok=0;
    }
    if(ok)ans++;
  }
  cout<<ans<<endl;
}

