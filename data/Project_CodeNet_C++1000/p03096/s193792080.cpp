#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7 , MOD = 1e9 + 7;
int dp[_] , sum[_] , arr[_] , pos , N;

int main(){
	scanf("%d" , &N); int pre = 0;
	for(int i = 1 , x ; i <= N ; ++i){
		scanf("%d" , &x);
		if(pre != x) arr[++pos] = pre = x;
	}
	dp[1] = sum[arr[1]] = 1;
	for(int i = 2 ; i <= pos ; ++i) sum[arr[i]] = (sum[arr[i]] + (dp[i] = sum[arr[i - 1]])) % MOD;
	cout << sum[arr[pos]]; return 0;
}