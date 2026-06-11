#include<iostream>
#include<vector>
#include<iomanip>
#include<cstring>
#define prDouble(x) cout << fixed << setprecision(10) << x
#define ll long long int 
#define ii pair<int,int>
#define fast_io ios_base::sync_with_stdio(false);
#define MOD 1000000007
using namespace std;
ll dp[22][1<<22];
ll f(vector<vector<int>>&comp,int currentIndex,int set)
{
	if(currentIndex == 0)
		return set==0?1:0;
	if(dp[currentIndex-1][set]!=-1)
		return dp[currentIndex-1][set];
	ll count = 0;
	for(int i = 0;i < comp.size();++i)
	{
		int mask = (1<<i);
		if(comp[currentIndex-1][i] == 1 && (mask&set)!=0)
			count = (count + f(comp,currentIndex-1,set&(~mask)))%MOD;
	}
	return dp[currentIndex-1][set]=count;
}
int main()
{
	fast_io;
	int n;
	cin >> n;
	vector<vector<int>>comp(n,vector<int>(n,0));
	for(int i = 0;i < n;++i)
	{
		for(int j = 0;j < n;++j)
			cin >> comp[i][j];
	}
	memset(dp,-1,sizeof(dp));
	int  set = ((1<<n)-1);
	cout << f(comp,n,set) << "\n";
	return 0;
}