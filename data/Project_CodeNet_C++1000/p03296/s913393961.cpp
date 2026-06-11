#include<bits/stdc++.h>
using namespace std;

int a[101],dp[101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1])	dp[i]=dp[i-1]+1;
		else	dp[i]=1;
		if(!(dp[i]&1))	ans++;
	}
	cout<<ans<<endl;
}
