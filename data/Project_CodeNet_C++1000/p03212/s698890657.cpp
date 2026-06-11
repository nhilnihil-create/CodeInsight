#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int dp[10][2][2][2][2];

int main(){
	int N;
	scanf("%d", &N);
	if(N < 357){
		printf("0\n");
		return 0;
	}
	vector<int> Nd;
	int n = 0;
	while(N > 0){
		Nd.push_back(N % 10);
		N /= 10;
		n++;
	}
	dp[0][0][0][0][0] = 1;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < 2; ++j){
			for (int k = 0; k < 2; ++k){
				for (int l = 0; l < 2; ++l){
					for (int m = 0; m < 2; ++m){
						for (int d = 3; d <= ((j || (Nd[n-1 - i] >=  7)) ? 7 : Nd[n-1 - i]); d += 2){
							dp[i + 1][j || (d < Nd[n-1 - i])][k || (d == 3)][l || (d == 5)][m || (d == 7)] += dp[i][j][k][l][m];
						}
					}
				}
			}
		}
	}
	int ans = dp[n][0][1][1][1] + dp[n][1][1][1][1];
	for (int i = 1; i < n; ++i){
		int this_digit = 1;
		for (int j = 0; j < i; ++j) this_digit *= 3;
		this_digit -= 3*(1<<i);
		this_digit += 3;
		ans += this_digit;
	}
	printf("%d\n", ans);
	return 0;
}