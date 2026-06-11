#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;
vector<ll> v;
ll N;
bool memo[2500][2500][2];
ll dp[2500][2500][2];
ll f(ll n,ll i,int z){
  if(memo[n][i][z]) return dp[n][i][z];
  memo[n][i][z]=true;
  if(i == N-1LL) return dp[n][i][z]=abs(v[N]-v[n]);
  if(i==0){
    ll ans = 0LL;
    for(ll j = i; j < N-1; j++){
      chmax(ans,f(j+1LL,j+1LL,1));
    }
    chmax(ans,abs(v[N]-v[n]));
    dp[n][i][z]=ans;
  }
  if(i==1){
    ll ans = INF;
    for(ll j = i; j < N-1LL; j++){
      chmin(ans,f(j+1LL,j+1LL,0));
    }
    chmin(ans,abs(v[N]-v[n]));
    dp[n][i][z]=ans;
  }
  return dp[n][i][z];
}

int main() {
  ll Z,W;
  cin>>N>>Z>>W;
  v.resize(N+1LL);
  v[0]=W;
  for(ll i = 0LL; i < N; i++) cin>>v[i+1];
  cout<<f(0,0LL,0)<<endl;
}