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
#define MOD 1000000007
#define INF -100000000000000
#define ordered_set tree<pair< ll int ,ll  int>, null_type,less<pair<ll int, ll int>>, rb_tree_tag,tree_order_statistics_node_update> 
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define lld long double
using namespace __gnu_pbds;
ll int f[200005]={0};
ll int dp[200005][2]={0};
//dp[i][0]=no of configs in which the ith node can be coloured white in its subtree
void dfs(ll int start,vector<ll int> v[],ll int parent)
{
	f[start]=-1;
	for(ll int i=0;i<v[start].size();i++)
	{
		if(f[v[start][i]]!=-1)
			dfs(v[start][i],v,start);
	}
	if(v[start].size()==1 && start!=1)
	{//cout<<start<<" "<<parent<<endl;
		dp[start][0]=dp[start][1]=1;
		dp[parent][0]=((dp[parent][0])%MOD*(dp[start][0]+dp[start][1])%MOD)%MOD;
		dp[parent][1]=(dp[parent][1]%MOD*dp[start][0]%MOD)%MOD;
	}
	else
	{//cout<<start<<" "<<parent<<endl;
		dp[parent][0]=((dp[parent][0])%MOD*(dp[start][0]+dp[start][1])%MOD)%MOD;
		dp[parent][1]=(dp[parent][1]%MOD*dp[start][0]%MOD)%MOD;
	}
}
int main()
{
    fast;
    ll int n;
    cin>>n;ll int i,x,y;
    vector<ll int> v[n+1];
    for(i=1;i<n;i++)
    {
    	cin>>x>>y;
    	v[x].PB(y);
    	v[y].PB(x);
    }
    if(n==1)
    {
    	cout<<2<<endl;
    	exit(0);
    }
    for(i=1;i<=n;i++)
    	dp[i][0]=dp[i][1]=1;
    dfs(1,v,0);
    cout<<(dp[1][0]+dp[1][1])%MOD<<endl;
    //cout<<dp[1][0]<<" "<<dp[1][1]<<endl;
   // for(i=1;i<=n;i++)
    //	cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
}