#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector<ll> wa(N);
  map<ll, ll> mp{};
  wa[0] = A[0];
  mp[wa[0]]++;
  for (int i = 1; i < N; i++) {
    wa[i] = wa[i - 1] + A[i];
    mp[wa[i]]++;
  }
  ll ans = 0;
  mp[0]++;
  for (auto s : mp) {
    ans += (s.second * (s.second - 1)) / 2;
  }
  cout << ans << endl;
}