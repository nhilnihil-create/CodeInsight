#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, Z, W; cin >> N >> Z >> W;
  vector<ll> a(N);
  for (int i = 0; i < N; i++) cin >> a.at(i);
  vector<vector<ll>> dp(N+1, vector<ll>(2));
  for (int i = N-1; i >= 0; i--) {
    dp.at(i).at(0) = -1;
    if (i == 0) dp.at(i).at(0) = abs(a.at(N-1) - W);
    else dp.at(i).at(0) = abs(a.at(N-1) - a.at(i-1));
    for (int j = i+1; j < N; j++) {
      dp.at(i).at(0) = max(dp.at(i).at(0), dp.at(j).at(1));
    }
    dp.at(i).at(1) = 1000000001;
    if (i == 0) dp.at(i).at(1) = abs(a.at(N-1) - Z);
    else dp.at(i).at(1) = abs(a.at(N-1) - a.at(i-1));
    for (int j = i+1; j < N; j++) {
      dp.at(i).at(1) = min(dp.at(i).at(1), dp.at(j).at(0));
    }
  }
  cout << dp.at(0).at(0) << endl;
}