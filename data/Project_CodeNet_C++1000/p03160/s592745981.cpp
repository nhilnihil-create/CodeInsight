#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = 1e9 + 5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> dp(n, INF);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j : {i + 1, i + 2}) {
      if (j < n) {
        dp[j] = min(dp[j], dp[i] + abs(a[i] - a[j]));
      }
    }
  }
  cout << dp[n - 1] << "\n";
  return 0; 
}
