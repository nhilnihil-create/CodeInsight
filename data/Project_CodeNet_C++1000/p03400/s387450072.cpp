#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
#define all(i) i.begin(),i.end()
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
  ll N,D,X;
  cin>>N>>D>>X;
  ll a[N];
  rep(i,N) cin>>a[i];
  ll ans;
  ll count=0;
  for(int i=0;i<N;i++){
    ll j=1;
    while(true){
      if(D>=1+a[i]*(j-1)&&D<1+a[i]*j){
        count+=j;
        break;
      }
      else{
        j++;
      }
    }
  }
  ans=count+X;
  cout<<ans<<endl;
}
