#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<ll, ll>> drink(N);
  for (int i = 0; i < N; i++) cin >> drink[i].first >> drink[i].second;
  sort(drink.begin(), drink.end());
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if (drink[i].second < M) {
      ans += drink[i].first * drink[i].second;
      M -= drink[i].second;
    }
    else {
      ans += drink[i].first * M;
      break;
    }
  }
  cout << ans << endl;
}
