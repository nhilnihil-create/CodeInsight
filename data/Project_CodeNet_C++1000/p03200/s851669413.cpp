#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string S;
  cin >> S;
  int N = S.size();
  ll ans = 0;
  ll cnt = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'W') {
      ans += i - cnt;
      cnt++;
    }
  }
  cout << ans << endl;
  return 0;
}