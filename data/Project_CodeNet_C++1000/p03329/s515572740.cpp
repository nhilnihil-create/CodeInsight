// C - Strange Bank
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	int dp[n+1];
	for(int i=0; i<=n; ++i) dp[i] = i;
	for(int yen=6; yen<=n; ++yen){
		for(int c=6; c<=yen; c*=6)
			dp[yen] = min(dp[yen], dp[yen-c] + 1);
		for(int c=9; c<=yen; c*=9)
			dp[yen] = min(dp[yen], dp[yen-c] + 1);
	}
	cout<< dp[n] <<endl;
}
