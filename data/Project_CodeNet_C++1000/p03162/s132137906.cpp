#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define pb push_back
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()

typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

//------------------------------------------------------//

int main(){
  int n;
  cin >> n;
  vec<int> a(n, 0);
  vec<int> b(n, 0);
  vec<int> c(n, 0);
  rep(i, n){
    cin >> a[i] >> b[i] >> c[i];
  }

  int dp[n+1][3];
  rep(i, n+1){
    dp[i][0] = 0;
    dp[i][1] = 0;
    dp[i][2] = 0;
  }

  repc(i, 1, n){
    dp[i][0] = max(dp[i-1][1]+a[i-1], dp[i-1][2]+a[i-1]);
    dp[i][1] = max(dp[i-1][0]+b[i-1], dp[i-1][2]+b[i-1]);
    dp[i][2] = max(dp[i-1][0]+c[i-1], dp[i-1][1]+c[i-1]);
  }

  cout << max(max(dp[n][0],dp[n][1]), dp[n][2]) << endl;

  return 0;
}