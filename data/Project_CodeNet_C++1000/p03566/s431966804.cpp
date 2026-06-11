#include <iostream>

using namespace std;

int t[105];
int v[105];
double dp[105][105];
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> t[i];
  for(int i = 0; i < n; i++) cin >> v[i];

  for(int i = 0; i <= n; i++) {
    for(int j = 0; j < 105; j++) {
      dp[i][j] = -1;
      }
    }
  

  dp[0][0] = 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= v[i]; j++) {
      if(dp[i][j] == -1) continue;
      for(int k = 0; k <= v[i]; k++) {
	if(abs(j - k) > t[i]) continue;
	double a = v[i] - j;
	double b = v[i] - k;
	if(a + b <= t[i]) {
	  double up = (v[i] + j) * a / (double)2;
	  double stay =  (t[i] - a - b) * v[i];
	  double down = (v[i] + k) * b / (double)2;
	  double c = up + stay + down;
	  dp[i+1][k] = max(dp[i+1][k],dp[i][j] + c);
	}
	else {
	  double x = (k - j + t[i]) / (double)2;
	  double y = (j - k + t[i]) / (double)2;
	  double vv = x + j;
	  double up = (j + vv) * x / (double)2;
	  double down = (vv + k) * y / (double)2;
	  double c = up + down;
	  dp[i+1][k] = max(dp[i+1][k],dp[i][j] + c);
	}
      }
    }
  }

  cout << fixed << dp[n][0] << endl;
}





	
