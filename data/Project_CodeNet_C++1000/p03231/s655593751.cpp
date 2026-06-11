#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll lcm(ll x, ll y){
  ll k = __gcd(x, y);
  ll z = (x / k)*y;
  return z;
}


int main (){
  ll n, m;
  cin >> n >> m;

  string s,t; 
  cin >> s >> t;

  ll num = lcm(n, m);
  bool f = true;

  vector<pair<ll, char>> v(n);
  for(ll i = 0; i < n; i++){
    v[i].second = s[i];
    v[i].first = 1 + (num/n)*i;
    
    if((m * i) % n == 0 && (m * i) / n < m){
      if(v[i].second != t[(m * i) / n]){cout << -1 << endl; f = false; break;}
    }
  }


  if(f){cout << num << endl;}
}