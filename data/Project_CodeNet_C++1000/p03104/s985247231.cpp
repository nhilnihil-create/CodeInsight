#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll f(ll n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n+1;
  if (n % 4 == 3) return 0;
  return 0;
}

int main() {
  ll a,b;
  cin >> a >> b;
  ll ans = f(max((ll)0,a-1)) ^ f(b);
  cout << ans << endl;
  return 0;
}
