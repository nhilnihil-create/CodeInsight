#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
using namespace std;
const long long INF=1e9+7;
const string alp="abcdefghijklmnopqrstuvwxyz"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;


int main() {
  ll N,M;
  cin>>N>>M;
  ll k[M];
  ll count[M];
  rep(i,M){
    count[i]=0;
  }
  ll s[M][N];
  for(int i=0;i<M;i++){
    cin>>k[i];
    for(int j=0;j<k[i];j++){
      cin>>s[i][j];
    }
  }
  ll p[M];
  ll ans=0;
  rep(i,M) cin>>p[i];
  for(int tmp=0;tmp<(1<<N);tmp++){
    bitset<10> c(tmp);
    for(ll i=0;i<N;i++){
      if(c.test(i)){
        for(ll j=0;j<M;j++){
          for(ll l=0;l<k[j];l++){
            if(s[j][l]==i+1){
              count[j]++;
            }
          }
        }
      }
    }
    bool j=true;
    for(int i=0;i<M;i++){
      if(count[i]%2!=p[i]){
        j=false;
      }
    }
    if(j) ans++;
    rep(i,M) count[i]=0;
  }
  cout<<ans<<endl;
}