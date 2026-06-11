#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define rep(i,n) for(ll i = 0; i < n; i++)

int main() {
  ll n,y;
  cin >> n >> y;
  rep(i,n+1) {
    rep(j,n+1) {
      if (n-i-j < 0) {
        continue;
      }
      if (10000*i + 5000*j + 1000*(n-i-j) == y) {
        cout << i << " " << j << " " << n-i-j << endl;
        exit(EXIT_SUCCESS);
      }
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
  return 0;
}