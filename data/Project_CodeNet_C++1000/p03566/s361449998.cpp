#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 100
#define MAX_T 200
#define MAX_V 100
double dp[MAX_T*MAX_N*2+2][MAX_V*2+2];
ll ttov[MAX_T*MAX_N*2+2];
ll nowt = 0, sumt;

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<long long> v(N-1+1);
	vector<long long> t(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&t[i]);
	}
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&v[i]);
	}

	// tの累積値から対応するvを計算する
	sumt = t[0]*2;
	for(int i = 0 ; i < MAX_T*MAX_N*2+2 ; i++){
		if (i == sumt && nowt < N) {
			nowt++;
			if (nowt < N) {
				sumt += t[nowt]*2;
				ttov[i] = min(v[nowt-1]*2, v[nowt]*2);
			} else {
				ttov[i] = 0;
			}
			continue;
		}
		if (nowt < N) {
			ttov[i] = v[nowt]*2;
		} else {
			ttov[i] = 0;
		}
	}

	// for(int i = 0 ; i <= sumt ; i++){
	// 	cout << i << " " << ttov[i] << endl;
	// }
	// cout << endl;

	dp[0][0] = 0;
	for(int i = 1 ; i < MAX_V*2+2 ; i++){
		dp[0][i] = -1;
	}

	for(int i = 1 ; i < MAX_T*MAX_N*2+2 ; i++){
		for(int j = 0 ; j < MAX_V*2+2 ; j++){
			dp[i][j] = -1;
			if (j <= ttov[i]) {
				if (j-1 >= 0 && dp[i-1][j-1] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+(j-0.5));
				if (dp[i-1][j] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j]+j);
				if (j+1 < MAX_V*2+2 && dp[i-1][j+1] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j+1]+(j+0.5));
			}
		}
	}
	

	// for(int i = 0 ; i <= sumt ; i+=2){
	// 	cout << i << " " << dp[i][0] << endl;
	// }

	printf("%.16f\n", dp[sumt][0]*0.25);
	// cout << dp[sumt][0] << endl;

	return 0;
}

