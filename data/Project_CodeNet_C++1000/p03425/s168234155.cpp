#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  string S[N];
  ll M = 0;
  ll A = 0;
  ll R = 0;
  ll C = 0;
  ll H = 0;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
    if (S[i][0] == 'M') {
      M++;
    } else if (S[i][0] == 'A') {
      A++;
    } else if (S[i][0] == 'R') {
      R++;
    } else if (S[i][0] == 'C') {
      C++;
    } else if (S[i][0] == 'H') {
      H++;
    }
  }
  ll ans = M*A*R + M*A*C + M*A*H + M*R*C + M*R*H + M*C*H + A*R*C + A*R*H + A*C*H + R*C*H;
  cout << ans << endl;
  return 0;
}
