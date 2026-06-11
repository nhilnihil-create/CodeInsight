
// Problem : I - Coins
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_i
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

// $%U%$
// Mere bas ka nahi hai
// still i'm trying
// apna time aayega
//
//        .--------------.  
//        | Try First One|
//        '--------------'
//                |     .--------------.
//                |     |              |
//                V     V              |
//              .--------------.       |
//              |      AC.     |<---.  |  
//              '--------------'    |  |
//              (True)|  |(False)   |  |
//           .--------'  |          |  |
//           |           V          |  |
//           |  .--------------.    |  |
//           |  |   Try Again  |----'  |
//           |  '--------------'       |
//           |                         |
//           |  .--------------.       |
//           '->| Try Next One |-------'
//              '--------------'                          		  
//
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll power(ll x,ll y,ll m){if(y==0)return 1;ll p=power(x,y/2,m)%m;p=(p*p)%m;return (y%2==0)?p:(x*p)%m;}
ll nCr(ll n,ll r,ll m){if(r>n)return 0;ll a=1,b=1,i;for(i=0;i<r;i++){a=(a*n)%m;--n;}while(r){b=(b*r)%m;--r;}return (a*power(b,m-2,m))%m;}
#define Test int t;cin>>t;while(t--)
#define endl '\n'
void solve()
{
	int n;
	cin >> n;
	vector<double> dp(n+1);
	dp[0]=1;
	for(int i=0;i<n;++i)
	{
		double t;
		cin >> t;
		for(int j=i+1;j>=0;--j)
		{
			if(j==0)
			dp[j]=dp[j]*(1-t);
			else
			dp[j]=dp[j-1]*t+dp[j]*(1-t);
		}
	}
	double ans=0;
	for(int i=1;i<=n;++i)
	{
		if(i>n-i)
		ans+=dp[i];
	}
	printf("%.10f",ans);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//Test
	solve();
	return 0;
}
