#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
  ll N, SA{}, SB{}, SD, ans{};
  cin >> N;
  vector<ll> A(N), B(N), D(N);
  for(ll &a: A) cin >> a, SA += a;
  for(ll &b: B) cin >> b, SB += b;
  for (int i = 0; i != N; ++i) {
    D[i] = A[i] - B[i];
  }
  if (SA < SB) ans = -1;
  else {
    sort(begin(D),end(D));
    int l = lower_bound(begin(D), end(D), 0) - begin(D);
    SD = accumulate(begin(D), begin(D) + l, 0ll);
    ans = l;
    for (int i = 1; N-i >= l; ++i) {
      if (SD>=0) break;
      ++ans;
      SD += D[N-i];
    }
  }
  cout << ans << endl;
}
