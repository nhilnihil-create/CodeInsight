#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  ll n,m;
  string s,t;
  cin >>n>>m>>s>>t;
  ll k = __gcd(n,m);
 
  ll x = n / k, y = m / k;
  for (int i = 0; i < k; i++)
  {
    if (s[i*x] != t[i*y]) {
      cout << -1 << endl;
      return 0;
    } 
  }
  cout << n/k*m << endl;
  return 0;
}