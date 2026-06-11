/*@author Vipen Loka*/
#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define deb(x) cout << #x << ':' << x << '\n';

using namespace std;

void solve(){
	int i,j;
	int n,sum=0;
	cin >> n;
	vector<long double > v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	vector<vector<long double>> dp(n+1,vector<long double>(n+1,0));

	dp[0][0]=(long double)1;

	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 0; j < n+1; ++j)
		{
			if(j){
				dp[i][j]=dp[i-1][j-1]*v[i-1];
			}
			dp[i][j]+=dp[i-1][j]*(1-v[i-1]);
		}
	}
	long double ans=0;
	for (int i = 0; i < n+1; ++i)
	{
		if(i>n-i)ans+=dp[n][i];
	}

	printf("%.10Lf\n",ans);


	
}


int main(){
	int T=1;
	// cin >> T;
	while (T--){
		solve();
	}
}
