#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int f[110][15];
int p[110][15];

int main(){
  int n;
  cin>>n;
  rep(i,n)rep(j,10) cin>>f[i][j];
  rep(i,n)rep(j,11) cin>>p[i][j];
  ll ans=LLONG_MIN;
  for(int i=1; i<(1<<10); i++){
    ll now=0;
    vector<int> c(n,0);
    rep(s,n){
      rep(j,10){
        if(i>>j&1 && f[s][j]==1) c[s]++;
      }
    }
    rep(j,n){
      now+=p[j][c[j]];
    }
    ans=max(ans,now);
  }
  cout<<ans<<endl;
}
