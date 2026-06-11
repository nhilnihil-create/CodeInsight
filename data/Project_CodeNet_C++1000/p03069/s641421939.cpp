#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  int N;
  string S;
  cin >> N >> S;
  ll ans = 1e10;
  vector<ll> wa(N + 1);
  wa[0] = 0;
  for (int i = 1; i <= N; i++) {
    wa[i] = wa[i - 1];
    if (S[i - 1] == '.') wa[i]++;
  }
  for (int i = 1; i <= N; i++) {
    ll l = wa[i];
    ll r = wa[N] - wa[i];
    ans = min(ans, (i - l) + (r));
  }
  ans = min(min(wa[N],ans), N - wa[N]);
  cout << ans << endl;
}