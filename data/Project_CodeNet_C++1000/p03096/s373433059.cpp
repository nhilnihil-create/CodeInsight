#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL

int main(){
	int N;
	cin >> N;
	vector<int> C(N);
	for(auto &i:C)cin >> i;
	
	vector<int> prev(222222,-1);
	vector<long long> dp(N,0);
	dp[0]=1;
	
	for(int i=0;i<N;i++){
		int p=prev[C[i]];
		prev[C[i]]=i;
		if(i==0)continue;
		if(p<0 || p==i-1)dp[i]=dp[i-1];
		else dp[i]=dp[i-1]+dp[p];
		dp[i]%=MOD;
	}
	//for(int i=0;i<N-1;i++)cout << dp[i] << " ";
	cout << dp[N-1] << endl; 
	return 0;
}