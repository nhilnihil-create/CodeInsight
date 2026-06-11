#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
  int n;
  cin>>n;
  vector<int> a(n+1);
  rep1(i,n) cin>>a[i];
  vector<int> l(n+1), r(n+1);
  rep1(i,n-1) l[i+1] = __gcd(l[i], a[i]);
  for (int i = n; i >= 2; --i) r[i-1] = __gcd(r[i], a[i]);
  int ans = 1;
  rep1(i,n) ans = max(ans, __gcd(l[i],r[i]));
  cout<<ans<<endl;
  return 0;
}