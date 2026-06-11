#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  ll N;
  cin >> N;
  vector<ll> A(0);
  for (int i = 2; i <= N / i; i++) {
    if (i == N / i) {
      A.push_back(i);
      continue;
    }
    if (N % i == 0) {
      A.push_back(i);
      A.push_back(N / i);
    }
  }
  A.push_back(N);
  ll ans = 0;
  REP(i, A.size()) {
    ll tmp = A[i] - 1;
    if (tmp == 0) continue;
    if (floor(N / tmp) == N % tmp) ans += tmp;
  }
  cout << ans << endl;
}