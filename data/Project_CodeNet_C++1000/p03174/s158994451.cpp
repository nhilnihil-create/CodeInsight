#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define FAST  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long int 
#define ar array
#define pb push_back
#define fi(a,b) for(int i=a;i<(b);i++)
#define fj(a,b) for(int j=a;j<(b);j++)
#define fk(a,b) for(int k=a;k<(b);k++)
#define lb lower_bound
#define ub upper_bound
//hash base 177013

const int mod=1e9+7;

int main()
{
	FAST;
	//#ifndef ONLINE_JUDGE
	//	freopen("input.txt","r",stdin);
	//	freopen("output.txt","w",stdout);
	//#endif
	//ll testcase;
	//cin>>testcase;
	//while(testcase--)
	{
		int n;
		cin>>n;
		int a[n+1][n+1];
		fi(0,n)
		{
			fj(0,n)
			{
				cin>>a[i][j];
			}
		}
		//return 0;
		int dp[1<<n];
		for(int i=0;i<(1<<n);i++)
		{
			dp[i]=0;
		}
		dp[0]=1;
		//return 0;
		for(int i=0;i<(1<<n);i++)
		{
			//return 0;
			int x=0;
			//cout<<q<<'\n';
			//exit(0);
			//cout<<i<<'\n';
			//return 0;
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j)) x++;
			}
			//exit(0);
			if(x>=n) break;
			//return 0;
			//cout<<x<<'\n';
			for(int j=0;j<n;j++)
			{
				//assert(x<n);
				//return 0;
				if(!(i&(1<<j))&&a[j][x])
				{
					//assert((i|(1<<j))<n);
					dp[i|(1<<j)]=(dp[i|(1<<j)]+dp[i])%mod;
				}
			}
			//return 0;
		}
		//fi(0,21)
		//{
			//cout<<dp[i]<<' ';
		//}
		//cout<<dp[0];
		cout<<dp[(1<<n)-1];
		
		
	}
}
