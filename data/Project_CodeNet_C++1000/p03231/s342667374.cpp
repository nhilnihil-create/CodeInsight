#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep1(i, n) for(ll i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b,a%b);
}

int main(){
  
  ll n,m;
  cin >> n >> m;
  string s,t;
  cin >> s >> t;
  ll g = gcd(n,m);
  ll cntN = 0;
  ll cntM = 0;
  while(cntN<n && cntM<m){
    if(s[cntN] != t[cntM]){
      cout << -1 << endl;
      return 0;
    }
    cntN += n/g;
    cntM += m/g;
  }
  cout << lcm(n,m) << endl;
}