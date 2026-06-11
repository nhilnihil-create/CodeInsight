#include<bits/stdc++.h>

using namespace std;
const int MOD=1e9+7;
map<int,int>mp;
int last[200005],c[200005],prep[200005],dp[200005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	memset(last,-1,sizeof(last));
	memset(prep,-1,sizeof(prep));
	for(int i=1;i<=n;i++){
		last[i]=prep[c[i]];
		prep[c[i]]=i;
	}
	dp[1]=1;
	for(int i=2;i<=n;i++){
		if(c[i]!=c[i-1]&&last[i]!=-1){
			dp[i]=(dp[i-1]+dp[last[i]])%MOD;
		}
		else {
		    dp[i]=dp[i-1];
		}
	}
	cout<<dp[n];
	return 0;
}