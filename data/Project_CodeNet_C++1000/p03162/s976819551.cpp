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

int main(){
	int n;
	cin >> n;
	vector<int> a(n) , b(n) , c(n);
  
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
  
	int dp[n + 100][3];
	for(int i = 0; i < n + 100; i++){
		for(int j = 0; j < 3; j++){
			dp[i][j] = 0;
		}
	}
  
	for(int i = 1; i <= n; i++){
		dp[i][0] += max((dp[i - 1][1] + a[i - 1]) , (dp[i - 1][2] + a[i - 1])); 
		dp[i][1] += max((dp[i - 1][0] + b[i - 1]) , (dp[i - 1][2] + b[i - 1])); 
		dp[i][2] += max((dp[i - 1][0] + c[i - 1]) , (dp[i - 1][1] + c[i - 1])); 
	}
  
	long long ans = max({dp[n][0] , dp[n][1] , dp[n][2]});
  
	cout << ans << endl;
  
	return 0;
}
 
