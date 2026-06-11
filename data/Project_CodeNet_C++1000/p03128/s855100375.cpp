#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#define DEBUG(x) cout << ">> " << #x << ": " << x << endl;
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;

int digit[] = {0,2,5,5,4,5,6,3,7,6};
 
int main() { _
  int n, m; cin >> n >> m;
  vector<pair<int, int>> dp(n+1, make_pair(-1, -1));
  dp[0] = make_pair(0, 0);
  vector<int> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for (int i = 1; i <= n; i++) {
    for (int j : v) {
      if (i - digit[j] < 0 || dp[i - digit[j]].first < 0) continue;
      if (dp[i - digit[j]].first + 1 >= dp[i].first) 
        dp[i].first = dp[i-digit[j]].first+1, dp[i].second = j;
    }
  }
  string s = "";
  for (int i = n; i != 0; i -= digit[dp[i].second])
    s.push_back('0' + dp[i].second);
  sort(s.begin(), s.end(), greater<char>());
  cout << s << endl;
  return 0;
}