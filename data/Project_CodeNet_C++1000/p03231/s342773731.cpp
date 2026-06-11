#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll x,ll y){
  if(x%y==0) return y;
  else gcd(y,x%y);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  ll G = gcd(n,m);
  ll L = (n*m)/G;
  
  if(s[0]!=t[0]){
    cout << -1 << endl;
    return 0;
  }
  if(G==1){
    cout << L << endl;
    return 0;
  }
  if(n>=m){
    ll N = n/G;
    ll M = m/G;
    bool ok = true;
    for(ll i=1;i<G;i++){
      if(s[N*i]!=t[M*i]) ok = false;
    }
    
    if(ok){
      cout << L << endl;
    }
    else{
      cout << -1 << endl;
    }
  }
  else{
    ll N = n/G;
    ll M = m/G;
    
    bool ok = true;
    for(ll i=1;i<G;i++){
      if(s[N*i]!=t[M*i]) ok = false;
    }
    
    if(ok){
      cout << L << endl;
    }
    else{
      cout << -1 << endl;
    }
  }
  return 0;
  
}
