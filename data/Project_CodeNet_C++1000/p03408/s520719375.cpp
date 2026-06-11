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
  map<string,ll> coin;
  cin>>N;
  rep(i,N){
    string d;
    cin>>d;
    coin[d]++;
  }
  cin>>M;
  rep(i,M){
    string d;
    cin>>d;
    coin[d]--;
  }
  ll ans=0;
  for(auto i=coin.begin();i!=coin.end();i++){
    ans=max(ans,i->second);
  }
  cout<<ans<<endl;
}
