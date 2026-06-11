#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool G[55][55];
bool visit[55];
ll N;

void dfs(ll n){
  visit[n] = true;
  for(ll j=0;j<=N-1;j++)
    if(G[n][j] && !visit[j]) dfs(j);
}

int main(){
  ll M,i,k;
  ll a,b;
  ll ans = 0;
  cin >> N >> M;
  for(i=0;i<=M-1;i++){
    cin >> a >> b;
    a--,b--;
    G[a][b] = G[b][a] = true;
    }
  for(i=0;i<=N-2;i++)
    for(k=i+1;k<=N-1;k++){
      if(G[i][k]){
        G[i][k] = false;
        G[k][i] = false;
        dfs(0);
        ll x = 0;
        for(ll m = 0;m<=N-1;m++)
          if(!visit[m]) x = 1;
        ans += x;
        G[i][k] = true;
        G[k][i] = true;
        for(ll m=0;m<=N-1;m++)
          visit[m] = false;
      }
    }
  cout << ans << endl;
}