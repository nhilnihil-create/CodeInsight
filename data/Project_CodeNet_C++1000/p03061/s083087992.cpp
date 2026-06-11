#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int main() {
  int n;
  cin >> n;
  vector<int> a(n), l(n+1), r(n+1);
  rep(i,n) cin >> a[i];
  l[0] = 0;
  for(int i = 1; i <= n; i++) {
    l[i] = gcd(l[i-1],a[i-1]);
  }
  r[n] = 0;
  for(int i = n-1; i >= 0; i--) {
    r[i] = gcd(r[i+1],a[i]);
  }
  int ans = 0;
  rep(i,n) {
    int g = gcd(l[i],r[i+1]);
    ans = max(ans,g);
  }

  cout << ans << endl; 
  return 0;
}