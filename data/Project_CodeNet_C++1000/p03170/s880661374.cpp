#include<bits/stdc++.h>
#define ll long long int
#define db long double
#define ull unsigned long long int
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define Nmax 1000005
#define INF 1000000000
#define MOD 1000000007
#define MAXN 1000005
 
using namespace std;

ll dp[100005];
ll a[105];
ll n;

ll recur(ll stones)
{
	if(stones<0) return 0;
	if(stones==0) return 1;
	if(dp[stones]!=-1) return dp[stones];
	ll res=0;
	for(ll i=1;i<=n;i++)
	{
		if(stones==a[i]) return dp[stones]=1LL;
	}
	for(ll i=1;i<=n;i++)
	{
		if(stones-a[i]<0) continue;
		if(recur(stones-a[i])) continue;
		return dp[stones]=1LL;
	}
	return dp[stones]=res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests=1;
    // cin>>tests;
    while(tests--)
    {	
    	ll i,j,k;
    	cin>>n>>k;
    	rep(i,1,n) cin>>a[i];
    	memset(dp,-1,sizeof(dp));
    	dp[0]=1;
    	if(recur(k)==1) cout<<"First";
    	else cout<<"Second";
    }
    	return 0;
    
}