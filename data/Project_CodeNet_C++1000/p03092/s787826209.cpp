#include<bits/stdc++.h>
using namespace std;

#define int long long
int dp[5003][5003] , arr[5003] , A , B , N;
void chkmin(int &a , int b){a = a < b ? a : b;}

signed main(){
	cin >> N >> A >> B;
	for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
	memset(dp , 0x3f , sizeof(dp)); dp[0][0] = 0;
	for(int i = 0 ; i < N ; ++i)
		for(int j = 0 ; j <= N ; ++j)
			if(j < arr[i + 1]){
				chkmin(dp[i + 1][arr[i + 1]] , dp[i][j]);
				chkmin(dp[i + 1][j] , dp[i][j] + A);
			}
			else chkmin(dp[i + 1][j] , dp[i][j] + B);
	int mn = 1e18; for(int i = 1 ; i <= N ; ++i) mn = min(mn , dp[N][i]);
	cout << mn; return 0;
}