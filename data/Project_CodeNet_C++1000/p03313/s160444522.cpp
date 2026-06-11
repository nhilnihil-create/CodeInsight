#include <iostream>

using namespace std;

const int MAX_N = 1 << 19;
const int MAX_LG = 20;

pair<int, int> dp [MAX_N][MAX_LG];
int ans [MAX_N];
int arr [MAX_N];

pair<int, int> merge (pair<int, int> p, pair<int, int> q) {
  if (p.first < q.first) {
    swap(p, q);
  }
  return make_pair(p.first, max(p.second, q.first));
}

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < 1 << length; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < 1 << length; i++) {
    dp[i][0] = make_pair(arr[i], -1);
  }

  for (int k = 1; k <= length; k++) {
    for (int i = 0; i < 1 << length; i++) {
      if (i & (1 << (k - 1))) {
        dp[i][k] = merge(dp[i][k - 1], dp[i - (1 << (k - 1))][k - 1]);
      } else {
        dp[i][k] = dp[i][k - 1];
      }
    }
  }

  for (int i = 1; i < 1 << length; i++) {
    ans[i] = max(ans[i - 1], dp[i][length].first + dp[i][length].second);
    cout << ans[i] << '\n';
  }
}
