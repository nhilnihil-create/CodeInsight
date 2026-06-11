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
  ll N;
  cin>>N;
  vector<pair<pair<string,ll>,ll>> res(N);
  rep(i,N){
    cin>>res[i].first.first>>res[i].first.second;
    res[i].first.second*=-1;
    res[i].second=i+1;
    
  }
  sort(res.begin(),res.end());
  rep(i,N){
    cout<<res[i].second<<endl;
  }
}
