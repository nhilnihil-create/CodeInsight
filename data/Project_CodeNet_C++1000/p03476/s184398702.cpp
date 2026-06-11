#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 100007;

vector<bool> is_prime(N, true);

void enum_prime() {
  rep(i, N) {
    if (i < 2) is_prime[i] = false;
    if (!(is_prime[i])) continue;
    for (int j = 2*i; j < N; j += i) is_prime[j] = false;
  }
  return;
}

int main() {
  enum_prime();
  vector<int> cum(N, 0);
  rep(i, N) {
    if (i == 0) continue;
    cum[i] = cum[i-1];
    if (i % 2 && is_prime[i] && is_prime[(i+1)/2]) cum[i]++;
  }

  int q;
  cin >> q;
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    int ans = cum[r] - cum[l-1];
    cout << ans << endl;
  }
  return 0;
}