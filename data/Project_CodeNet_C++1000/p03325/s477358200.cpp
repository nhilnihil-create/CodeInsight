#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, ans = 0;
  cin >> n;
  rep(i,n) {
    ll x;
    cin >> x;
    while(x%2==0) {
      x /= 2;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}