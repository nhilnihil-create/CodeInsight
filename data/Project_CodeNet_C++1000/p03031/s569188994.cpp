#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  
  vector<vector<int>> S(m);
  int k,s;
  rep(i,m){
    cin>>k;
    rep(j,k){
      cin>>s;
      S[i].push_back(s-1);
    }
  }
  
  vector<int> P(m);
  rep(i,m) cin>>P[i];
  
  int cnt,ans=0;
  for(int bit=0;bit<(1<<n);bit++){
    bool b=true;
    rep(i,m){
      cnt=0;
      rep(j,S[i].size()){
        if(bit&(1<<S[i][j])) cnt++;
      }
      if(cnt%2!=P[i]) b=false;
    }
    if(b) ans++;
  }
  
  cout<<ans<<endl;

  return 0;
}