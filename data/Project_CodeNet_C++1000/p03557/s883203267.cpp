#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;

  vector<ll> A(n), B(n), C(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  rep(i, n) cin >> C[i];

  sort(A.begin(), A.end());
  sort(C.begin(), C.end());
  
  ll ans = 0;
  rep(i, n) {
    ll num_a = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
    ll num_c = C.end() - upper_bound(C.begin(), C.end(), B[i]);
    // cout << num_a << ' ' << num_c << endl;
    ans += num_a * num_c;
  }

  cout << ans << endl;
  return 0;
}
