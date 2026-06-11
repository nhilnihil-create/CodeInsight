#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll H,W,ans=0;
  cin >> H >> W;
  queue<P> Q;
  vector<string> A(H);
  vector<vector<ll>> dp(H,vector<ll>(W,INF));
  rep(i,H){
    cin >> A.at(i);
    rep(j,W){
      if(A.at(i).at(j)=='#'){
        Q.push(P(i,j));
        dp.at(i).at(j)=0;
      }
    }
  }
  while(!Q.empty()){
    ll h,w;
    h=Q.front().first;
    w=Q.front().second;
    Q.pop();
    if(h!=0&&dp.at(h-1).at(w)==INF){
      dp.at(h-1).at(w)=dp.at(h).at(w)+1;
      ans=max(ans,dp.at(h-1).at(w));
      Q.push(P(h-1,w));
    }
    if(h!=H-1&&dp.at(h+1).at(w)==INF){
      dp.at(h+1).at(w)=dp.at(h).at(w)+1;
      ans=max(ans,dp.at(h+1).at(w));
      Q.push(P(h+1,w));
    }
    if(w!=0&&dp.at(h).at(w-1)==INF){
      dp.at(h).at(w-1)=dp.at(h).at(w)+1;
      ans=max(ans,dp.at(h).at(w-1));
      Q.push(P(h,w-1));
    }
    if(w!=W-1&&dp.at(h).at(w+1)==INF){
      dp.at(h).at(w+1)=dp.at(h).at(w)+1;
      ans=max(ans,dp.at(h).at(w+1));
      Q.push(P(h,w+1));
    }
  }
  cout << ans << endl;
}