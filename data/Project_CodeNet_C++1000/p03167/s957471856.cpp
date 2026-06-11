#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007

int main(){
	int H,W;
	cin >> H >> W;
	vector<vector<char>> maze(H,vector<char>(W));
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			cin >> maze[i][j];
		}
	}

	vector<vector<int>> dp(H+1,vector<int>(W+1));
	for(int i=1; i<=H; i++){
		for(int j=1; j<=W; j++){
			if(i==1 && j==1){ dp[i][j] = 1; continue; } 
			if(maze[i-1][j-1] == '.'){
				dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % INF;
			}
		}
	}

	cout << dp[H][W] << endl;
}

