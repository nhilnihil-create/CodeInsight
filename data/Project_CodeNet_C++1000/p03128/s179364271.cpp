#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl

const int INF = 1000000;
const int MAXK = 1000005;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> A(m);
  rep(i, m) cin >> A[i];
  sort(all(A));
  vector<int> K = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  vector<int> dp(MAXK, -INF);
  dp[0] = 0;
  for(int j = 0; j <= n; j++)
    rep(i, m) dp[j + K[A[i]]] =
      max(dp[j + K[A[i]]], dp[j] + 1);

  int rem = dp[n];
  string s;
  int j = n;
  while(j > 0) {
    for(int i = m - 1; i >= 0; i--) {
      if(j - K[A[i]] < 0) continue;
      if(dp[j - K[A[i]]] == rem - 1) {
        char c = '0' + A[i];
        s = s + c;
        j -= K[A[i]];
        rem--;
        break;
      }
    }
  }
  cout << s << endl;
  return 0;
}