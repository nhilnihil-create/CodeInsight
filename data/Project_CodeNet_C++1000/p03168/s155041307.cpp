#include<iostream>
#include<iomanip>
#include<string>
#include<list>
using namespace std;

typedef long double ld;

int main() {
  int N; cin >> N;
  ld P[N]; for (int i = 0; i < N; i++) cin >> P[i];
  ld dp[N+1][N+1];
  dp[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= i; j++) dp[i][j] = 0;
    for (int j = 0; j < i; j++) {
      dp[i][j] += (1 - P[i-1]) * dp[i-1][j];
      dp[i][j+1] += P[i-1] * dp[i-1][j];
    }
  }
  ld sum = 0;
  for (int j = N/2+1; j <= N; j++) sum += dp[N][j];
  cout << setprecision(15) << sum << endl;
}