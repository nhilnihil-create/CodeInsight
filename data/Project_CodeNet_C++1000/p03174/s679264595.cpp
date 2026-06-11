#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int dp[1<<21];

int main() 
{
	int n;
	scanf("%d", &n);
	vector<vector<int>> v(n+1, vector<int>(n+1));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &v[i][j]);
		}
	}
	dp[0] = 1;
	for(int i = 0; i < (1<<n); i++) {
		bitset<32> bit_(i);
		int one = bit_.count();
		for(int j = 0; j < n; j++) {
			if(v[one][j] == 1) {
				if(!(i&(1<<j))) {
					dp[(1<<j)|i] += dp[i];
					dp[(1<<j)|i] %= mod;
					// printf("___dp[(1<<j)|i] : %d___ : %d\n", dp[(1<<j)|i], (1<<j)|i);
				}
			}
		}
	}
	printf("%d\n", dp[(1<<n)-1]);
}