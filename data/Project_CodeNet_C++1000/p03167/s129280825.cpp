#include<bits/stdc++.h>
using namespace std;
int a[1000+200][1000+200];
long long int dp[1000+200][1000+200];

int main(int argc, char const *argv[])
{
	int H, W;
	while(cin >> H >> W) {
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=H; i++){
			for(int j=1; j<=W; j++){
				char temp;
				cin >> temp;
				if(temp == '.'){
					a[i][j] = 0;
				} else {
					a[i][j] = 1;
				}
			}
		}
		dp[1][1] = 1;
		const unsigned int M = 1000000007;
		for(int i=1; i<=H; i++) {
			for(int j=1; j<=W; j++) {
				if(i == 1 && j == 1) continue;
				if(!a[i][j]){
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
				    dp[i][j] %= M;
				}
			}
		}
		cout << dp[H][W] << endl;
	}
	return 0;
}