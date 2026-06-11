#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  ll N;
  vector<ll> A(5);
  cin >> N;
  rep(i,5) cin >> A[i];
  ll s = A.size();
  ll ans = 0;
  rep(i,5) {
    ll res = (N + (A[i]-1)) / A[i];
    ans = max(ans, res+s-1);
  }
  cout << ans << endl;
}