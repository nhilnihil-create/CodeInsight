#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');

void solve(long long N){
  ll res = 0;
  repr(i,1,N+1){
    if (i % 2 == 0) continue;
    ll c = 0;
    repr(j, 1, i + 1) if (i % j == 0)++ c;
    if (c == 8) ++res;
  }
  cout << res << endl;
}

int main() {
long long N;
    scanf("%lld",&N);
  solve(N);
}
