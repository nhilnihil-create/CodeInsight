#include<bits/stdc++.h>

using namespace std;

int n,m;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
long long dp[MAXN];
long long s[MAXN];

map<long long, long long> mp;

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	int last=-1;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		if(tmp==last) continue;
		s[++m]=tmp;
		last=tmp;
	}
	dp[0]=dp[1]=1;mp[s[1]]=1;
	for(int i=2;i<=m;i++){
		//int siz=mp[s[i]].size();
		if(mp[s[i]]){
			dp[i]=(dp[i-1]+mp[s[i]])%MOD;
			mp[s[i]]=(mp[s[i]]+dp[i-1])%MOD;
		}
		else{
			dp[i]=dp[i-1];
			mp[s[i]]=dp[i-1];
		}
	}
	cout<<dp[m]%MOD<<endl;
/*	for(int i=0;i<=m;i++){
		cout<<i<<' '<<dp[i]<<endl;	
	}*/
	return 0;
}