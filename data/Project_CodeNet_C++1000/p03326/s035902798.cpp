#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long llint;
#define inf 1e18

llint n,m;
llint x[1005],y[1005],z[1005];

llint a[8] = {1, 1, 1, 1, -1, -1, -1, -1};
llint b[8] = {1, 1, -1, -1, 1, 1, -1, -1};
llint c[8] = {1, -1, 1, -1, 1, -1, 1, -1};

llint dp[1005][1005];

llint calc(int p)
{
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = -inf;
		}
	}
	dp[0][0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= m; j++){
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			if(j < m){
				dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + (a[p]*x[i+1] + b[p]*y[i+1] + c[p]*z[i+1]));
			}
		}
	}
	return dp[n][m];
}
void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> x[i] >> y[i] >> z[i];
	}
	llint ans=0;
	for(int i = 0; i < 8; i++){
		ans = max(ans, calc(i));
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
