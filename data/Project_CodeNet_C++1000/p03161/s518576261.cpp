#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long
const int INF=1e9+7;

int main(){
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\User\\Documents\\input.txt","r",stdin);
#endif
	int T,i,j;
	
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1),dp(n+1,INF);
	for(i=1;i<=n;++i){
	    scanf("%d",&a[i]);
	}
	dp[1]=0;

	for(i=1;i<n;++i){
	    for(j=i+1;j<=min(n,i+k);++j){
	        dp[j]=min(dp[j],dp[i]+abs(a[j]-a[i]));
	    }
	}
	printf("%d\n",dp[n]);

		
	return 0;
}