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
  ll a[5];
  rep(i,5) cin>>a[i];
  ll b[5];
  ll ans=INF;
  ll sum=0;
  rep(i,5){
    if(a[i]%10==0){
      b[i]=a[i];
    }
    else{
      b[i]=a[i]+(10-a[i]%10);
    }
    sum+=b[i];
  }
  rep(i,5){
    ll mi=sum;
    mi-=b[i];
    mi+=a[i];
    ans=min(ans,mi);
  }
  cout<<ans<<endl;
}