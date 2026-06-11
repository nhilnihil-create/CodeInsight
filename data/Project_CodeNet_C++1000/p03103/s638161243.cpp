#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}



int main(){
  ll n,m;
  cin >> n >> m;

  map<ll,ll> mp;
  rep(i,n){
    ll a,b;
    cin >> a >> b;
    mp[a] += b;
  }

  ll ans = 0;
  for(auto it : mp){
    ll c = it.first;
    ll b = it.second;

    if(b>=m){
      b = m;
      ans += c*m;
      cout << ans << endl;
      break;
    }else{
      m-=b;
      ans += c*b;
    }
  }


  return 0;
} 

