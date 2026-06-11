#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll gcd(ll x,ll y){
  if(x%y==0) return y;
  else gcd(y,x%y);
}

int main() {
  ll n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  ll G = gcd(n,m);
  ll L = (n*m)/G;
  
  bool can;
  if(s[0]!=t[0])can = false;
  else if(G==1) can = true;
  else{
    ll N = n/G;
    ll M = m/G;
    bool ok = true;
    for(ll i=1;i<G;i++){
      if(s[N*i]!=t[M*i]) ok = false;
    }    
    if(ok) can = true;
    else can = false;
  }
  ll ans = can ? L : -1;
  cout << ans << endl;
  return 0; 
}
