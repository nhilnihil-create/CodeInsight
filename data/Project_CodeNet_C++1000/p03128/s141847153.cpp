#include <bits/stdc++.h>
using namespace std;

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

int main() {
  int n, m; cin >> n >> m;
  vector<int> arr(m);
  for (int i = 0; i < m; ++i) {
    cin >> arr[i];
  }
  map<int, int> match;
  vector<int> match_nums = {2,5,5,4,5,6,3,7,6};
  for (int i = 1; i < 10; ++i) {
    match[i] = match_nums[i - 1];
  }
  vector<cpp_int> dp(n + 7, -1);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int a: arr) {
      if (dp[i] == -1) continue;
      cpp_int new_dp = dp[i] * 10 + a;
      if (dp[i + match[a]] < new_dp) dp[i + match[a]] = new_dp;
    }
  }
  cout << dp[n] << endl;
}
