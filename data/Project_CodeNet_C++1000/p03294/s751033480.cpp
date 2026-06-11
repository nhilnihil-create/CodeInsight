#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  rep(i,n) {
    ll tmp;
    cin >> tmp;
    tmp--;
    ans += tmp;
  }
  cout << ans << endl;
  return 0;
}