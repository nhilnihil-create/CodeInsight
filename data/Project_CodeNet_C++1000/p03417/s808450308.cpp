//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
int main(){
  ll n,m;
  cin>>n>>m;
  ll ans;
  if(n==1 && m==1)ans=1;
  if(n>=3 && m>=3)ans=(n-2)*(m-2);
  if(n==2 || m==2)ans=0;
  if(n==1 && m>=3)ans=m-2;
  if(n>=3 && m==1)ans=n-2;
  cout<<ans<<endl;
}