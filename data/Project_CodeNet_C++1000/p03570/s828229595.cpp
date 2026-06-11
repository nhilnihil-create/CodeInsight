#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a)) 

const int N=2e5+5;
const int INF=0x3f3f3f3f;
int dp[(1<<26)+5];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	mem(dp,INF);
	dp[0]=0;
	int mark=0;
	int ans=0;
	for(int i=0;i<s.size();i++)
	{
		mark^=1<<(s[i]-'a');
		dp[mark]=dp[mark]+1;
		for(int j=0;j<26;j++)
		{
			dp[mark]=min(dp[mark^(1<<j)]+1,dp[mark]);
		}		
		ans=dp[mark];
		dp[0]=0;
	}
	cout<<ans<<endl;
	return 0;
}