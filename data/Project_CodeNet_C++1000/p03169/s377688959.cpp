#include <bits/stdc++.h>
using namespace std;
using ll = long long;
double dp[310][310][310];

signed main(){
	int n, a = 0, b = 0, c = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x == 1) a++;
		if(x == 2) b++;
		if(x == 3) c++;
	}
	double N = n;
	dp[1][0][0] = double(n);
	for(int k = 0; k <= n; k++){
		for(int j = 0; j <= n; j++){
			for(int i = 0; i <= n ; i++){
				if((i == 0 || i == 1) && j == 0 && k == 0) continue;
				if(i){
					dp[i][j][k] += dp[i - 1][j][k] * (i / N);
				}
				if(j){
					dp[i][j][k] += dp[i + 1][j - 1][k] * double(j / N);
				}
				if(k){
					dp[i][j][k] += dp[i][j + 1][k - 1] * double(k / N);
				}
			  dp[i][j][k] *= double(N / (i + j + k));
				dp[i][j][k] += double(N / (i + j + k));
			}
		}
	}
	cout << setprecision(10) << dp[a][b][c] << endl;
}

	