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
  ll n,k;
  cin>>n>>k;
  if(k%2==0){
    ll a=n/k;
    ll b=n/(k/2)-a;
    cout<<a*a*a+b*b*b<<endl;
  }
  else {
    ll a=n/k;
    cout<<a*a*a<<endl;
  }
}