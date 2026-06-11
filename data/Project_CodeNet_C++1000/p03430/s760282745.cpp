#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
static const int INF = 1000000000;
static int dp[301][301][301];

int main(){
	ios_base::sync_with_stdio(false);
	int k;
	string s;
	cin >> s >> k;
	string t(s);
	reverse(t.begin(), t.end());
	const int n = s.size();
	for(int i = 0; i <= k; ++i){
		for(int x = 0; x <= n; ++x){
			for(int y = 0; y <= n; ++y){ dp[i][x][y] = -INF; }
		}
	}
	dp[0][0][0] = 0;
	for(int i = 0; i <= k; ++i){
		for(int x = 0; x <= n; ++x){
			for(int y = 0; y <= n; ++y){
				const int cur = dp[i][x][y];
				if(x < n && y < n){
					if(s[x] == t[y]){ dp[i][x + 1][y + 1] = max(dp[i][x + 1][y + 1], cur + 1); }
					if(i < k){ dp[i + 1][x + 1][y + 1] = max(dp[i + 1][x + 1][y + 1], cur + 1); }
					dp[i][x + 1][y + 1] = max(dp[i][x + 1][y + 1], cur);
				}
				if(x < n){ dp[i][x + 1][y] = max(dp[i][x + 1][y], cur); }
				if(y < n){ dp[i][x][y + 1] = max(dp[i][x][y + 1], cur); }
				if(i < k){ dp[i + 1][x][y] = max(dp[i + 1][x][y], cur); }
			}
		}
	}
	/*
for(int i = 0; i <= k; ++i){
	for(int x = 0; x <= n; ++x){
		for(int y = 0; y <= n; ++y){ cout << dp[i][x][y] << " " ;}
		cout << endl;
	}
	cout << endl;
}
*/
	int answer = 0;
	for(int i = 0; i <= n; ++i){
		answer = max(answer, 2 * dp[k][i][n - i]);
	}
	for(int i = 1; i <= n; ++i){
		answer = max(answer, 1 + 2 * dp[k][i - 1][n - i]);
	}
	cout << answer << endl;
	return 0;
}
