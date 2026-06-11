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

  vector<ll> d;
  ll i = 1;
  while(i*i <= m){
    if(m%i==0){
      d.push_back(i);
      d.push_back(m/i);
    }
    i++;
  }

  sort(d.begin(), d.end(), greater<ll>());
  

  rep(j,d.size()){
    if(d[j]*n<=m){
      cout << d[j] << endl;
      return 0;
    }
  }

  

  return 0;
} 