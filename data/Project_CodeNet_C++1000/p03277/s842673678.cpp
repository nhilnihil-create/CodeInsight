#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const ll INF = 1e17;

template <typename T>
class BIT {
  int n;
  vector<T> bit;
public:
  BIT(int _n) {
    n = _n;
    bit = vector<T>(n+1,(T)0);
  }
  T sum(int i) {
    T s = 0;
    while(i > 0){
    s += bit[i];
    i -= i & -i;
  }
  return s;
  }
  void add(int i, T x) {
    while(i <= n){
    bit[i] += x;
    i += i & -i;
    }
  }
};

int main(){
  ll n;
  cin >> n;
  ll a[n+1];
  rep(i,n) cin >> a[i+1];
  ll l = 0, r = INF;
  while(r - l > 1) {
    ll m = (l + r) / 2;
    vector<ll> s(n+1,0);
    BIT<ll> bit(3*n);
    bit.add(2*n,1);
    ll num = 0;
    for(ll i = 1; i <= n; i++) {
      s[i] = s[i-1];
      if(a[i] >= m) s[i]++;
      else s[i]--;
      ll k = s[i] + 2*n;
      num += bit.sum(k);
      bit.add(k,1);
    }
    if(num >= (n*(n+1)/2 +1)/2) l = m;
    else r = m;
  }
  cout << l << endl;
}
