#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 100001;
int arr[N][3];
int dp[N][2][2][2];
ll findans(bool f, bool s, bool t, int n){
	if(n < 0) return 0;
	ll ans = 0;
	if(dp[n][(int)f][(int)s][(int)t]) return dp[n][(int)f][(int)s][(int)t];
	if(f && s){
		ans = max(findans(0, 1, 1, n - 1) + arr[n][0], findans(1, 0, 1, n - 1) + arr[n][1]);
	}
	if(f && t){
		ans = max(ans, max(findans(0, 1, 1, n - 1) + arr[n][0], findans(1, 1, 0, n - 1) + arr[n][2]));
	}
	if(s && t){
		ans = max(ans, max(findans(1 ,0 ,1 ,n - 1) + arr[n][1], findans(1, 1, 0, n - 1) + arr[n][2]));
	}
	dp[n][(int)f][(int)s][(int)t] = ans;
	return dp[n][(int)f][(int)s][(int)t];
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp, 0, sizeof(dp));
	int n;
	cin >> n;
	for(int i= 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			cin >> arr[i][j];
		}
	}

	cout << findans(1, 1, 1, n - 1);

	
	
}
