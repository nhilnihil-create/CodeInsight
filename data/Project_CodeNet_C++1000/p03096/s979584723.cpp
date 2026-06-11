#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
using namespace std;
typedef long long int lld;
typedef pair<int, int> pii;

const lld M = 1000000007;
const int MAXN = 200002;

int n, m;
int arr[MAXN];
lld bucket[MAXN];
lld dp[MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int act = -1;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (x == act) continue;
    act = arr[m++] = x;
  }

  dp[0] = 1;
  bucket[arr[0]] = 1;
  for (int i = 1; i < m; ++i) {
    dp[i] = dp[i-1] + bucket[arr[i]];
    bucket[arr[i]] += dp[i-1];
    dp[i] %= M;
    bucket[arr[i]] %= M;
  }
  cout << dp[m-1] << "\n";
  return 0;
}