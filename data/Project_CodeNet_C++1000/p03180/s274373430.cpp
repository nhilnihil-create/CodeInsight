#include <bits/stdc++.h>
 
using namespace std;

typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
typedef vector<vector<lli> > vvi;
typedef vector<ii> vii;

#define EB emplace_back
#define PB push_back
#define MP make_pair
#define FF first
#define SS second

const int mod = 1e9 +7;
lli a[16][16], n, dp[131072];
int abc, cnt;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	for(int m=1; m<(1LL<<n); m++)
	{
		for(int i=0; i<n; i++)
		{
			if((m>>i)&1)
			{
				for(int j=i; j<n; j++)
					if((m>>j)&1) dp[m]+=a[i][j];
			}
		}
		abc = (1LL<<(__builtin_popcount(m)-1)), cnt=0;
		for (int s=m; s&&cnt<=abc; s=(s-1)&m)
			dp[m] = max(dp[m], dp[s]+dp[m^s]), cnt++;
	}
	cout << dp[(1LL<<n)-1];
}