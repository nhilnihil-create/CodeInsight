#include <bits/stdc++.h>
#define REP(i, n) for (long i = 0; i < n; ++i)
#define FOR(i, b, n) for (long i = b; i < n; ++i)

using namespace std;

void solve(long N, vector<long> A) {
  long ans(A.front());
  FOR(i, 1, N)
    ans = __gcd(ans, A[i]);
  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  long N;
  cin >> N;
  vector<long> A(N);
  REP(i, N)
    cin >> A[i];

  solve(N, move(A));

  return 0;
}
