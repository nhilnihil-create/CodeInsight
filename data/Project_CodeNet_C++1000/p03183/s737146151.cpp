#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN=1024;
const int MAXW=2e4+10;
LL dp[MAXN][MAXW];
struct data{
	int w,s,t;
	LL v;
}a[MAXN];
int n;
LL ans;

bool cmp(data x,data y){
	return x.t<y.t;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].w>>a[i].s>>a[i].v;
		a[i].t=a[i].s+a[i].w;
	}
	
	sort(a+1,a+n+1,cmp);
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i].t;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=a[i].w){
				dp[i][j]=max(dp[i][j],dp[i-1][j-a[i].w]+a[i].v);
			}
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
 