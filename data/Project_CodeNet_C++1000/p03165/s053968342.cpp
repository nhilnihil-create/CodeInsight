#include<bits/stdc++.h>
#define ll long long int
#define mod 10000000007
#define mod2 998244353
#define pb push_back
#define ru(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define mp make_pair
#define inp(a,n) ru(i,n){cin>>a[i];}
#define sv(v) sort(v.begin(),v.end())
#define sa(a) sort(a,a+size(a)/size(a[0]))
using namespace std;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

const int mw=1e9+10;
ll dp[3010][3010];

string a,b;



void solve(int m,int n)
{
	 ru(i,m+1)
	 ru(j,n+1)
	 {
		 if(j==0||i==0)
		 dp[i][j]=0;
		 else if(a[i-1]==b[j-1])
		 dp[i][j]=dp[i-1][j-1]+1;
		 else
		 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	 }
}
string ans(int m,int n)
{
	string an="";
	int i=m,j=n;
	while(i&&j)
	{
		if(a[i-1]==b[j-1])
		{
			an=a[i-1]+an;
			i--;j--;
		}
		else if(dp[i-1][j]>=dp[i][j-1])
		{
			i--;
		}
		else
		j--;
	}
	return an;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t=1;
	//cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		cin>>a>>b;
		int m=a.size(),n=b.size();
		//cout<<
		solve(m,n);
		//cout<<dp[m][n]<<"\n";
		cout<<ans(m,n);
	}
return 0;
}
