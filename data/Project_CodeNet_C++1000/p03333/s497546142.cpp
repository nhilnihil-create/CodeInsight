#include<bits/stdc++.h>
using namespace std;

using I = long long;

int main() {
  I N;
  cin >> N;

  vector<I> L(N+1), R(N+1);
  for(auto i=0; i<N; ++i) cin >> L[i] >> R[i];
  L[N] = R[N] = 0;
  sort(begin(L), end(L), greater<I>());
  sort(begin(R), end(R));

  I ans = 0;
  I l = 0, r = 0;
  for(auto i=0; i<N; ++i) {
    l += L[i];
    r += R[i];
    ans = max(ans, 2 * (l - r));
  }
  cout << ans << endl;
}
