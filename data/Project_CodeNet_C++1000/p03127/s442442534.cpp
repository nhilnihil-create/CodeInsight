#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep2(i, s, n) for(ll i = s; i < n; i++)
using namespace std;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  while(1){
    vector<ll> b;
    b.push_back(a[0]);
    rep2(i, 1, n){
      ll x;
      x = a[i] % a[0];
      if (x != 0) b.push_back(x);
    }
    sort(b.begin(), b.end());
    a = b;
    n = a.size();
    if (n == 1) break;
  }
  cout << a[0] << endl;
  
  return 0;
}