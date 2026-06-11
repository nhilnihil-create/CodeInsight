#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0)
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define int long long
const int MOD=1e9+7;
const int N=3e5+10;
int dp[N],a[N];
int32_t main()
{
	IOS;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i]=1e18;
	}
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=i-1;j>=max(1LL,i-k);j--)
		{
			dp[i]=min(dp[i],dp[j]+abs(a[i]-a[j]));
		}
	}
	cout<<dp[n]<<endl;
	

}