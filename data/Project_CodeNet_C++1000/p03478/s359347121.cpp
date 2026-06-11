#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll N, A, B; cin >> N >> A >> B;
  ll ans = 0;

  for(int i = 1; i < N+1; i++) {
    string s = to_string(i);
    ll tmp = 0;
    rep(j, s.size()) {
      tmp += s[j] - '0';
    }
    if (A <= tmp && tmp <= B) {
      ans += i;
    }

  }

  cout << ans << endl;
  return 0;
}