#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n,m; cin >> n >> m;
  ll ans;
  if (n==1 && m==1) ans = 1;
  else if (n==1 && m != 1) ans = m-2;
  else if (m==1 && n != 1) ans = n-2;
  else {
    ans = (n-2)*(m-2);
  }
  cout << ans << endl;
  return 0;
}