#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  ll ans = 0;
  ll right = 0;
  ll tot = 0;  // AND 和
  rep(left, N) {
    while (right < N && (tot ^ A[right]) == (tot + A[right])) {
      tot += A[right];
      right++;
    }

    ans += (right - left);

    if (right == left)
      right++;
    else
      tot -= A[left];  // A[left] を削除 (tot ^= a[left] でも OK)
  }

  cout << ans << endl;

  return 0;
}
