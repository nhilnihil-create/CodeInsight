#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N, K, A[105];
ll DP[105][int(1e5+5)], sum[105][int(1e5+5)];

int main(){
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];
  DP[0][K] = 1;
  sum[0][K] = 1;

  for (int i = 1; i <= N; i++){
    DP[i][0] = sum[i-1][A[i]];
    for (int j = 1; j <= K; j++){
      int M = min(j+A[i], K);
      DP[i][j] = (sum[i-1][M] - sum[i-1][j-1]) % MOD;
      if (DP[i][j] < 0) DP[i][j] += MOD;
    }

    sum[i][0] = DP[i][0];
    for (int j = 1; j <= K; j++){
      sum[i][j] = (sum[i][j-1] + DP[i][j]) % MOD;
    }
  }

  cout << DP[N][0] << endl;

  return 0;
}
