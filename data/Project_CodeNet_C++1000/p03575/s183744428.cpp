#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
/*
1-2
3-4
5-6
*/
ll inf = 1e9;
vector<vector<ll>> G(51, vector<ll>(51,inf));
ll N,M,ans = 0;

void wf(){
  vector<vector<ll>> H(51, vector<ll>(51,inf));
  H = G;
  for(ll k=1; k<=N; k++) for(ll i=1; i<=N; i++) for(ll j=1; j<=N; j++)
    H[i][j] = min(H[i][j], H[i][k] + H[k][j]);
  for(ll i=1; i<=N; i++) for(ll j=1; j<=N; j++)
    if (H[i][j] == inf)
    {
      ans++;
      return;
    }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  cin >>N >>M;
  vector<pair<ll,ll>> P;  
  rep(i,M){
    ll a,b; cin>>a>>b;
    P.push_back({a,b});
    G[a][b] = 1;
    G[b][a] = 1;
  }
  rep(i, N+1)
    G[i][i] = 0;
  ll sz = P.size();
  rep(i,sz)
  {
    ll p1=P[i].first;
    ll p2=P[i].second;
    G[p1][p2] = inf;
    G[p2][p1] = inf;
    wf();
    G[p1][p2] = 1;
    G[p2][p1] = 1;
  }
  cout <<ans <<endl;
}