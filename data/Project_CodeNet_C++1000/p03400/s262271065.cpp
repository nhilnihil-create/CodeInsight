#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
ll euclidean_gcd(ll a, ll b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}


int main() {
  int n, d, x;
  cin >> n >> d >> x;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  int ans = x;
  rep(i,n){
    int day = (d-1)/a[i]+1;
    ans += day;
  }
  cout << ans << endl;
  return 0;
}