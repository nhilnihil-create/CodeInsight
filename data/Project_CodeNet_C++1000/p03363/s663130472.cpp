#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  ll ans=0;
  map<ll,ll> m;
  m[0]++;
  ll a=0;
  rep(i,n){
    ll o;
    cin >> o;
    a+=o;
    m[a]++;
  }
  for(pair<ll,ll> b: m){
    ll v=b.second;
    ans+=(v-1)*v/2;
  }
  cout << ans << endl;
}
