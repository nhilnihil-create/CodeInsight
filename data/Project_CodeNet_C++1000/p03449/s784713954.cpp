#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
constexpr ll mod = 1e9 + 7;
const int MOD = 1000000007;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int A[2][N];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
  int dp[2][N];
  dp[0][0] = A[0][0];
  dp[1][0] = A[0][0] + A[1][0];
  for (int i = 1; i < N; i++) {
    dp[0][i] = dp[0][i - 1] + A[0][i];
    dp[1][i] = max(dp[0][i], dp[1][i - 1]) + A[1][i];
  }
  cout << dp[1][N - 1];
  return 0;
}