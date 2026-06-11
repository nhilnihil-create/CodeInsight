#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
  int N, x;
  cin >> N >> x;
  vector<ll> a(N);
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum == x) {
    cout << N << endl;
    return 0;
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  ll subs = 0;
  for (int i = 0; i < N; i++) {
    subs += a[i];
    if (subs <= x) {
      ans = i + 1;
    }
  }
  if (ans == N) ans--;
  cout << ans << endl;
  return 0;
}