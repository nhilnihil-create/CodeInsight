#include<bits/stdc++.h>

#define IO    if(fopen("input.txt","r")) freopen("input.txt","r",stdin),freopen("output.txt","w",stdout)
#define boost     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll        long long int
#define pb        push_back
#define mp        make_pair
#define pii       pair<ll,ll>
#define mii       map<ll,ll>
#define ff        first
#define ss        second
#define fill(a,b) memset(a, b, sizeof(a))
#define endl      '\n'
#define all(x)    (x).begin(), (x).end()
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define print2d(dp,n,m) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++)cout<<dp[i][j]<<" ";cout<<"\n";}

const   long long M = 100005, inf = 2000000000000000000;

using namespace std;

void solve(){
ll a[M],b[M],c[M],dp[M],dp2[M],dp3[M];

	ll n,i;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	dp[1]=a[1];
	dp2[1]=b[1];
	dp3[1]=c[1];
	for(i=2;i<=n;i++){
		dp[i]=a[i]+max(dp2[i-1],dp3[i-1]);
		dp2[i]=b[i]+max(dp[i-1],dp3[i-1]);
		dp3[i]=c[i]+max(dp[i-1],dp2[i-1]);
	}

   cout<<max3(dp[n],dp2[n],dp3[n])<<endl;	
return;

}
	

signed main(){
	IO;
	boost;
	ll t;
	t=1;
	// cin>>t;
	while(t--){
		solve();
	}

}