#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<vector>
#define prDouble(x) cout << fixed << setprecision(10) << x
#define MOD 1000000007
#define fast_io ios_base::sync_with_stdio(false)
#define ii pair<int,int>
#define ll long long int 
using namespace std;
int dp[100001][2];
vector<int>tree[100001];
ll solve(int root,int par,int isCon)
{
	if(dp[root][isCon] != -1)
		return dp[root][isCon];
	ll result = 0;
	ll w,b;
	w = b = 1;
	for(int child:tree[root])
	{
		if(child != par)
			w = (w * solve(child,root,0))%MOD;
	}
	result = (result+ w)%MOD;
	if(!isCon)
	{
		for(int child:tree[root])
		{
			if(child != par)
				b = (b * solve(child,root,1))%MOD;
		}
		result = (result + b)%MOD;
	}
	return dp[root][isCon] = result;
}
int main()
{
	int n,x,y;
	cin >> n;
	for(int i = 0;i < n-1;++i)
	{
		cin >> x >> y;
		tree[x-1].push_back(y-1);
		tree[y-1].push_back(x-1);
	}
	memset(dp,-1,sizeof(dp));
	cout << (solve(0,-1,0)) << "\n";
	return 0;
}