#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define all(a) (a).begin(), (a).end()

int N, X, Y;
vector<int> a;

const int INF = 1e9+1;
int main () {
  cin >> N >> X >> Y;
  a.resize(N);

  rep(i,N) cin >> a[i];

  vector<vector<int>> dp({vector<int>(N, -INF), vector<int>(N, INF)});

  for(int i = N - 1; i >= 0; --i) {
    dp[0][i] = max(dp[0][i], abs((i - 1 >= 0 ? a[i-1] : Y) - a[N-1]));
    for(int j = i + 1; j < N; ++j) {
      dp[0][i] = max(dp[0][i], dp[1][j]);
    }
    dp[1][i] = min(dp[1][i], abs((i - 1 >= 0 ? a[i-1] : X) - a[N-1]));
    for(int j = i + 1; j < N; ++j) {
      dp[1][i] = min(dp[1][i], dp[0][j]);
    }
  }

  cout << dp[0][0] << endl;
  return 0;
}
