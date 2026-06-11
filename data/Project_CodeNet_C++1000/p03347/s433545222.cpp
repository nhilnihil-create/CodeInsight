#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  int now = 0;
  REP(i, N) {
    int a;
    cin >> a;
    A[i] = a;
    if (i > 0) {
      if (A[i] > 1 + A[i - 1]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  if (A[0] != 0) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  for (int i = 1; i < N; i++) {
    if (A[i] == A[i - 1] + 1) {
      ans++;
    } else {
      ans += A[i];
    }
  }
  cout << ans << endl;
}