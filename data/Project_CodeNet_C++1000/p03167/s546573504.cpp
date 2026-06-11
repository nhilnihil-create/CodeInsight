#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const int MOD = 1000000007;
const int dx[] = {1, 0};
const int dy[] = {0, 1};

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>> a(h, vector<char>(w));
	for(int i = 0; i < h; i++){
		string s;
		cin >> s;
		for(int j = 0; j < w; j++){
			a[i][j] = s[j];
		}
	}
	vector<vector<int>> dp(h, vector<int>(w));
	dp[0][0] = 1;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(i == 0 && j == 0) continue;
			for(int k = 0; k < 2; k++){
				int yp = i - dy[k];
				int xp = j - dx[k];
				if(0 <= yp && yp < h && 0 <= xp && xp < w && a[i][j] != '#') dp[i][j] += dp[yp][xp];
				if(dp[i][j] > MOD) dp[i][j] %= MOD;
			}
			if(dp[i][j] > MOD) dp[i][j] %= MOD;
		}
	}
	cout << dp[h - 1][w - 1] << endl;
}
