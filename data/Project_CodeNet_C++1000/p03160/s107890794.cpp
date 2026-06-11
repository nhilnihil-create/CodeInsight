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
	
	int n;
	cin>>n;
	vector<int> dp(n+1,INF),a(n+1);

	for(i=1;i<=n;++i){
	    scanf("%d",&a[i]);
	}
	dp[1]=0;
	for(i=1;i<n;i++){
		dp[i+1]=min(dp[i+1],dp[i]+abs(a[i+1]-a[i]));
		if(i+2<=n) dp[i+2]=min(dp[i+2],dp[i]+abs(a[i+2]-a[i]));
	}
	printf("%d\n",dp[n]);



	return 0;
}