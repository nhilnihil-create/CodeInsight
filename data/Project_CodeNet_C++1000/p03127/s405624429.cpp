#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define FOR(i, b, n) for (ll i = b; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve(ll N, vector<ll> A) {

  sort(A.begin(), A.end());
  ll min_ix = 0;
  while (min_ix < N - 1 && A[min_ix + 1] > 0) {
    ll mini = A[min_ix];
    FOR(i, min_ix + 1, N) {
      A[i] -= (A[i] / mini) * mini;
    }
    sort(A.begin(), A.end());
    min_ix = lower_bound(A.begin(), A.end(), 1) - A.begin();
  }
  cout << A.back() << endl;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) {
    cin >> A[i];
  }

  solve(N, move(A));

  return 0;
}
