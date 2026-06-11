#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define endl "\n"
#define pi 3.14159265358979323846264338327950288
#define MOD 1000000000000000
#define INF -100000000000000
#define ordered_set tree<pair< ll int ,ll  int>, null_type,less<pair<ll int, ll int>>, rb_tree_tag,tree_order_statistics_node_update> 
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define lld long double
using namespace __gnu_pbds;
int main()
{
    fast;
    ll int n;
    cin>>n;
    ll int a[n+1];
    ll int i,j,k,w;
    for(i=1;i<=n;i++)
    	cin>>a[i];
    ll int dp[n+1][n+1];
    for(i=0;i<=n;i++)
    {
    	for(j=0;j<=n;j++)
    		dp[i][j]=MOD;
    }
    ll int l[n+1];
    l[1]=a[1];
    for(i=2;i<=n;i++)
    	l[i]=l[i-1]+a[i];
    //dp[i][j]== min cost in which we can make (i,j) slimes convert to one slime.
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=(n-i+1);j++)
    	{
    		w=(j+i-1);
    		if(j==w)
    		{
    			dp[j][w]=a[j];
    			continue;
    		}
    		if(i==2)
    		{
    			dp[j][w]=a[j]+a[w];continue;
    		}
    		for(k=j;k<=w;k++)
    		{
    			if(k==j)
    				dp[j][w]=min(dp[j][w],dp[k+1][w]+l[w]-l[j]+a[j]);
    			else if(k==w)
    				dp[j][w]=min(dp[j][w],dp[j][w-1]+l[w]-l[j]+a[j]);
    			else 
    				dp[j][w]=min(dp[j][w],(dp[j][k]+dp[k+1][w])+l[w]-l[j]+a[j]);
    		}
    	}
    }
    cout<<dp[1][n]<<endl;
   

}