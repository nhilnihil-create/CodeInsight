#include<bits/stdc++.h>
using namespace std;
int stone[100000+5];
int dp[100000+5];

int main(int argc, char const *argv[])
{
	int N;
	while(cin >> N) {
		memset(stone, 0, sizeof(stone));
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=N; i++){
			cin >> stone[i];
		}
		dp[1] = 0;
		dp[2] = abs(stone[2] - stone[1]);
		for(int i=3; i<=N; i++){
			dp[i] = min(dp[i-2] + abs(stone[i] - stone[i-2]), dp[i-1] + abs(stone[i] - stone[i-1]));
		}
		cout << dp[N] << endl;
	}
	return 0;
}