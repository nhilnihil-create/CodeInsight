#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )

int N;
vector<int> A;
int dp[2][100001];

int dfs(int pre, int n) {
  // cout << pre << " " << n << endl;
  if ( n == N ) return 0;
  if ( dp[pre][n] >= 0 ) return dp[pre][n];

  int ret;
  if ( n == N-1 ) {
    ret = A[n];
    if ( pre ) ret *= -1;
  } else if ( pre ) {
    ret = max(-A[n] + dfs(0, n+1), A[n] + dfs(1, n+1));
  } else {
    ret = max(A[n] + dfs(0, n+1), -A[n] + dfs(1, n+1));
  }

  return dp[pre][n] = ret;
}
 
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  fill_n(*dp, 2*100001, -1);

  cin >> N;
  A.resize(N);
  REP(i, N) {
    cin >> A[i];
  }

  cout << dfs(0, 0) << endl;

  return 0;
}
