#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

const long long inf = 1e9 + 7;

int main(){
	int n , k;
	cin >> n >> k;
	vector<int> h(n+1);
	for(int i = 1; i <= n; i++)cin >> h[i];
	
	vector<int> dp(100100 , inf);
	dp[0] = 0;
	dp[1] = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= i + k; j++){
			dp[j] = min(dp[j] , dp[i] + abs(h[i] - h[j]));
		}
	}
	
	cout << dp[n] << endl;
	
	return 0;
}
 