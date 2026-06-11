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
  ll n;cin>>n;
  vl a;
  a.push_back(0);
  rep(i,n){
    ll x;cin>>x;
    a.push_back(x);
  }
  a.push_back(0);
  ll sum=0;
  rep(i,n+1)sum+=abs(a[i+1]-a[i]);
  rep(i,n)cout<<sum-(abs(a[i+1]-a[i])+abs(a[i+2]-a[i+1])-abs(a[i+2]-a[i]))<<endl;
}
  