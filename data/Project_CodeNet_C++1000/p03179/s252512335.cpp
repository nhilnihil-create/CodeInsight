#include<iostream>
#include<algorithm>
#include<cstring>
#include<numeric>
#include<vector>
using namespace std;

#define int long long

#ifdef lioraju
	#define ndbg(x) 
#else
	#define ndbg(x) x
#endif

const int mxsz = 3e3 + 5;
const int mod = 1e9 + 7;

int dp[mxsz][mxsz];

signed main()
{
	ndbg( ios::sync_with_stdio(0); cin.tie(0); );
	int n; cin>>n;
	string v; cin>>v;
	
	for (int i=0;i<n;i++)
	{
		if (!i) dp[i][i] = 1;
		else
		{
			vector<int> prf(n), suf(n);
			for (int k=0;k<n;k++) prf[k] = (!k? 0: prf[k-1]) + dp[i-1][k], prf[k] %= mod;
			for (int k=n-1;k>=0;k--) suf[k] = (k==n-1? 0: suf[k+1]) + dp[i-1][k], suf[k] %= mod;
			
			for (int k=0;k<=i;k++)
			{
				if (v[i-1]=='<') dp[i][k] = (!k? 0: prf[k-1]);
				else dp[i][k] = (k==i? 0: suf[k]);
			}
		}
	}
	
	int sum = 0;
	for (int i=0;i<n;i++) sum += dp[n-1][i], sum %= mod;
	cout<<sum<<'\n';
}