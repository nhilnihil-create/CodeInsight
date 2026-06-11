/*input
2
1 2 3 1
*/
#include<bits/stdc++.h>
using namespace std;
const int N=18;
const int mod=1e9 + 7;
#define int long long
#define pii pair<int, int>
#define f first
#define s second 
#define mp make_pair
int dp[(1<<N)][2], n, arr[(1<<N)];
struct comp
{
	bool operator()(int a, int b)
	{
		return (arr[a]>=arr[b]&&a!=b);
	}
};
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<(1<<n);i++) cin>>arr[i];
	dp[0][0]=0;dp[0][1]=-1;int ans=0;
	for(int i=1;i<(1<<n);i++)
	{
		set<int, comp> inds;inds.insert(i);
		for(int j=0;j<n;j++)
		{
			if((i&(1<<j))) 
			{
				int prev=(i^(1<<j));
				inds.insert(dp[prev][0]);
				if(dp[prev][1]!=-1) inds.insert(dp[prev][1]);
			}
		}
		dp[i][0]=(*inds.begin());
		inds.erase(inds.begin());
		dp[i][1]=-1;
		if(!inds.empty()) dp[i][1]=(*inds.begin());
		//if(i==(1<<n)-1) cout<<dp[i][0]<<" "<<dp[i][1]<<endl<<endl;
		ans=max(ans, arr[dp[i][1]] + arr[dp[i][0]]);cout<<ans<<endl;
	}
}