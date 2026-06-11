#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops") 
#include<bits/stdc++.h>
 
#define ll 			long long int 
#define pb          push_back
#define	endl		'\n'
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define dep(i,a,b)	for(int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;
 
#define N  105
ll mod=1e9+7;
ll a[25][25];
 ll dp[25][2100000];
 string s;
 int n;
 int d;
 int rec(int i, int mask,int cnt)
 {
 	if(i==n)
 	{
 		if( cnt==n)
 		return 1;
 	return 0;
 	}
 	ll &res=dp[i][mask];
 	if(res!=-1)
 		return res;
 	res=0;
 	if(n-cnt!=n-i)
 		return 0;
 	rep(j,0,n)
 	{
 		if(a[i][j]&&!(mask&(1<<j)))
 		{
 			res=(res+rec(i+1,int(1<<j|mask),cnt+1))%mod;

 			res=(res+rec(i+1,mask,cnt))%mod;
 		}
 		else
 			res=(res+rec(i+1,mask,cnt))%mod;

 	}
 	return res;
 	
 }
void solve()
{

	memset(dp,-1,sizeof(dp));
	
	
	//int n;
	cin>>n;
	rep(i,0,n)
	{
		rep(j,0,n)
		cin>>a[i][j];
	}
	cout<<rec(0,0,0)%mod;
	

}
	
	
 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
	#ifndef ONLINE_JUDGE
    	// for getting input from input.txt
    	freopen("input.txt", "r", stdin);
    	// for writing output to output.txt
    	freopen("output.txt", "w", stdout);
	#endif
    	
    
   //cin>>TESTS;
	int p=1;
	while(TESTS--)
	{
		//cout<<"CASE #"<<p<<":"<<" ";
		solve();
		p++;
		
		
	}
	return 0;
}