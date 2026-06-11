//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n;cin>>n;
  ll m;cin>>m;
  vl a(n);
  rep(i,n)cin>>a[i];
  map<ll,ll>M;
  M[0]++;
  vl sum(n);
  sum[0]=a[0];
  sum[0]%=m;
  M[sum[0]]++;
  rep(i,n-1){
    sum[i+1]=a[i+1]+sum[i];
    sum[i+1]%=m;
    M[sum[i+1]]++;
  }
  ll ans=0;
  for(auto p:M){
    ans+=p.second*(p.second-1)/2;
  }
  cout<<ans<<endl;
}
  
  
