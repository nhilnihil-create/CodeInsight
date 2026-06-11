#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int last[200010];
int dp[200010];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		dp[i]=dp[i-1];
		if(last[x]!=i-1&&last[x]){
			dp[i]+=dp[last[x]];
			if(dp[i]>=mod)
				dp[i]-=mod;
		}
		last[x]=i;
	}
	cout<<dp[n]<<endl;
	
}
