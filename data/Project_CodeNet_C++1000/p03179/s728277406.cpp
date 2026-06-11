#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0)
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
typedef long long ll;
#define pri(n) printf("%d\n",n)
#define lpri(n) printf("%lld\n",n);
#define rep(i,st,ed) for(int i=st;i<ed;i++)
#define var(n) int n; scn(n)
#define F first
#define S second 
#define pb(n) push_back(n)
const int N=3003;
const ll M=1e9+7;
const ll inf=1e18;

int dp[N][N];
void add(int& a,int b)
{
	a+=b;
	if(a>=M)
		a-=M;
}

int main()
{
	ios;
	int n;
	string s;
	cin>>n>>s;

	dp[1][1]=1;
	for(int len = 2;len<=n;len++)
	{
		for(int j=1;j<=len;j++)
			add(dp[len-1][j],dp[len-1][j-1]);
		for(int cur = 1;cur<=len;cur++)
		{
			if(s[len-2]=='<')
				add(dp[len][cur],dp[len-1][cur-1]);
			else
				add(dp[len][cur],(dp[len-1][len]-dp[len-1][cur-1]+M)%M);
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
		add(ans,dp[n][i]);
	cout<<ans<<endl;
}