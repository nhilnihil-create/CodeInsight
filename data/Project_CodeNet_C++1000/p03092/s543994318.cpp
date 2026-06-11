#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 5e3 + 5;
const ll INF = 1e14;

ll dp [MAX_N][MAX_N];
int arr [MAX_N];
ll premin [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  ll A, B;
  cin >> A >> B;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  
  for (int i = 1; i <= n; i++) {
    premin[0] = dp[i - 1][0];
    for (int j = 1; j <= n; j++) {
      premin[j] = min(premin[j - 1], dp[i - 1][j]);
    }
    
    for (int j = 0; j <= n; j++) {
      if (arr[i] < j) {
	dp[i][j] = dp[i - 1][j] + B;
      } else if (arr[i] == j) {
	dp[i][j] = premin[j - 1];
      } else if (arr[i] > j) {
	dp[i][j] = dp[i - 1][j] + A;
      }
    }
  }

  ll ans = INF;
  for (int j = 1; j <= n; j++) {
    ans = min(ans, dp[n][j]);
  }
  cout << ans << endl;
}
