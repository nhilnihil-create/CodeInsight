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
	vector<int> h(n);
	for(int i = 0; i < n; i++)cin >> h[i];
	vector<int> dp(100100 , 0);
	for(int i = 1; i < n; i++){
		if(i == 1){
			dp[i] += abs(h[i] - h[i - 1]);
		}else{
			dp[i] += min(abs(h[i] - h[i - 1]) + dp[i - 1] , abs(h[i] - h[i - 2]) + dp[i - 2]);
		}
	}
	cout << dp[n - 1] << endl;
	
	return 0;
}
 
