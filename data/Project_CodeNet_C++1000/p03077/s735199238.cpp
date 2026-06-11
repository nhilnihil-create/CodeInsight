#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n;
  cin >> n;
  ll mi=1001001001001001;
  rep(i,5) {
    ll x;
    cin >> x;
    mi=min(mi,x);
  }

  ll ans = (n+mi-1)/mi+4;

  cout << ans << endl;
}
