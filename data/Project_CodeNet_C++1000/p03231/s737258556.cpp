#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll gcd(ll a,ll b){
  if(a%b==0)
    return(b);
  else
    return(gcd(b,a%b));
}

int main(){
  ll n,m;
  string s,t;
  cin >> n >> m >> s >> t;
  ll l=n*m/gcd(n,m);
  int ans=1;
  ll g=gcd(n,m);
  for(int i=0;i<g;i++){
    if(s[i*(n/g)]!=t[i*(m/g)]) ans=0;
  }
  if(ans) cout << l << endl;
  else cout << -1 << endl;
}