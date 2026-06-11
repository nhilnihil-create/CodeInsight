#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll N,Z,W;
vector<ll> a;
ll dp[2][2005];
bool seen[2][2005];
ll f(ll x,ll z){
  if(seen[x][z]) return dp[x][z];
  seen[x][z] = true;
  if(z==N-1) dp[x][z] = abs(a[N]-a[N-1]);
  if(x==0){
    for(int i = z+1;i<N; i++) chmax(dp[x][z],f(1,i));
    chmax(dp[x][z],abs(a[N]-a[z]));
  }
  else{
    for(int i = z+1;i<N;i++) chmin(dp[x][z],f(0,i));
    chmin(dp[x][z],abs(a[N]-a[z]));
  }
  return dp[x][z];
}

int main(){
  cin>>N>>Z>>W;
  a.resize(N+1);
  a[0] = W;
  rep(i,2){
    rep(j,2005){
        if(i==0) dp[i][j]=0;
        else dp[i][j] = INF;
    }
  }
  rep(i,N) cin>>a[i+1];
  ll ans = 0;
  rep(i,N-1){
    chmax(ans,f(1,i+1));
  }
  chmax(ans,abs(W-a[N]));
  cout<<ans<<endl;
}