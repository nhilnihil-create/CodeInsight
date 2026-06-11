#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const ll MOD = 1e9+7; ll LLINF = 1LL << 60; int INF = INT_MAX;

//

int main(){
      ll n; cin>>n;
      vector<ll> f(n,0);
      vector<vector<ll>> p(n,vector<ll>(10,0));
      rep(i,0,n){
            for(int j=9; j>=0; j--){
                  int x; cin>>x;
                  if(x!=0) f[i] |= (1 << j);
            }
      }
      rep(i,0,n){
            rep(j,0,11){
                  cin>>p[i][j];
            }
      }
      ll ans=-LLINF;
      for(ll i=1; i<(1<<10); i++){
            ll cnt=0;
            rep(j,0,n){
                  cnt= cnt+p[j][__builtin_popcount(f[j] & i)];
            }
            ans=max(cnt,ans);
      }
      cout<<ans<<endl;


}