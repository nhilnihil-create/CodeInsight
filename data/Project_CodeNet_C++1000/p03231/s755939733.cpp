#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

ll gcd(int n, int m){
  if(n < m) swap(n,m);

  if(m==0) return 0;
  while(m > 0){
    int res = n%m;
    n = m;
    m = res;
  }
  return n;
}

int lcm(int n, int m){
  return m*n/gcd(n,m);
}


int main(){
  ll n,m;
  string s,t;
  cin >> n >> m >> s >> t;

  ll l = lcm(n,m);
  bool ok = true;
  rep(i,gcd(n,m)) ok &= s[l/m*i]==t[l/n*i];
  cout<< (ok ? l : -1) << '\n';
  return 0;
}
