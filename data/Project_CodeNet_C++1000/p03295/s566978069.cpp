#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, M;
  cin >> N >> M;
  vector<pll> rec(M);
  for (ll i = 0; i < M; ++i) {
    cin >> rec.at(i).first >> rec.at(i).second;
  }
  sort(rec.begin(), rec.end(), [] (pll a, pll b) {
    return a.second < b.second;
  });
  ll last = -1;
  ll ans = 0;
  for (ll i = 0; i < M; ++i) {
    if (rec.at(i).first <= last) {
      continue;
    }
    ans += 1;
    last = rec.at(i).second -= 1;
  }
  cout << ans << "\n";
}
