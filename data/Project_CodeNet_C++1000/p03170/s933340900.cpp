#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long
#define pb push_back
#define mod 1000000007
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define inf 1e18
#define pre(x,y) fixed<<setprecision(y)<<x
#define pq priority_queue<int>
#define mpq priority_queue<int,vector<int>,greater<int>>
#define gcd(x,y) __gcd(x,y)
#define mp make_pair



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i,j,k;
    cin>>n>>k;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    vector<int> dp(k+1,0);
    dp[0]=0;
    for(i=1;i<=k;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		if(i-a[j]>=0)
    		{
    			if(dp[i-a[j]]==0) {dp[i]=1;break;}
    		}
    	}
    }
    if(dp[k]) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
	return 0;
}
