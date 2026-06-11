#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 100005

char S[SIZE];
ll dp[SIZE][4];

int main(){

	scanf("%s",S);

	int len;
	for(len = 0; S[len] != '\0'; len++);

	for(int i = 0; i <= len; i++){
		for(int k = 0; k < 4; k++){

			dp[i][k] = 0;
		}
	}

	dp[0][0] = 1;

	for(int i = 0; i < len; i++){

		//状態を進めない
		for(int k = 0; k < 4; k++){
			if(S[i] != '?'){

				dp[i+1][k] += dp[i][k];

			}else{

				dp[i+1][k] += 3*dp[i][k];
			}
			dp[i+1][k] %= MOD;
		}

		//状態を進める
		if(S[i] == 'A' || S[i] == '?'){

			dp[i+1][1] += dp[i][0];
			dp[i+1][1] %= MOD;
		}
		if(S[i] == 'B' || S[i] == '?'){

			dp[i+1][2] += dp[i][1];
			dp[i+1][2] %= MOD;
		}
		if(S[i] == 'C' || S[i] == '?'){

			dp[i+1][3] += dp[i][2];
			dp[i+1][3] %= MOD;
		}
	}

	printf("%lld\n",dp[len][3]);

	return 0;
}
