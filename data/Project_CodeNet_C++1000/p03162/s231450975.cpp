#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100002][4];

ll vacation(ll a[],ll b[], ll c[], int prev, ll n){
	if(n==0)
		return 0;
	
	if(dp[n][prev]!=-1)
		return dp[n][prev];

	if(prev==0)
		return dp[n][0] = max(a[n] + vacation(a,b,c,1,n-1), max(b[n] + vacation(a,b,c,2,n-1), c[n] + vacation(a,b,c,3,n-1)));
	if(prev==1)
		return dp[n][1] = max(b[n] + vacation(a,b,c,2,n-1), c[n] + vacation(a,b,c,3,n-1));
	if(prev==2)
		return dp[n][2] = max(a[n] + vacation(a,b,c,1,n-1), c[n] + vacation(a,b,c,3,n-1));
	if(prev==3)
		return dp[n][3] = max(b[n] + vacation(a,b,c,2,n-1), a[n] + vacation(a,b,c,1,n-1));
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n+1],b[n+1],c[n+1];
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i]>>c[i];
    }
    memset(dp,-1,sizeof(dp));
    int prev=0;
    cout<<vacation(a,b,c,prev,n);
}
