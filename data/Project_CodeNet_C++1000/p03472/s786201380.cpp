#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int main() {
  int N, H;
  cin >> N >> H;
  vector<ll> A(N), B(N);
  ll maxa = 0;
  REP(i, N) { cin >> A[i] >> B[i]; }
  sort(A.begin(), A.end(), greater<ll>());
  sort(B.begin(), B.end(), greater<ll>());
  A.push_back(0);
  B.push_back(0);
  ll b = 0;
  ll ans = 0;
  while (H > 0) {
    if (B[b] > A[0]) {
      H -= B[b];
      b++;
      ans++;
    } else {
      ans += (H + A[0] - 1) / A[0];
      H = 0;
    }
  }
  cout << ans << endl;
}