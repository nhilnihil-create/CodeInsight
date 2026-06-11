#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define INF 1000000007
#define mod 1005
#define ll long long int
const double mx = 2e6 + 5 ;

void solve()
{
	int n;
	cin>>n;
	int maxPos = 0;
	vector<int> v(n), c(n);
	REP(i,n)
		cin>>v[i];
	REP(i,n)
		cin>>c[i];
	for(int i=0; i<(1<<n); i++)
	{
		int X = 0, Y = 0;
		for(int j=0; j<n; j++)
		{
			if((i&(1<<j)))
			{
				Y+=c[j];
				X+=v[j];
			}
		}
		maxPos = max(maxPos, X-Y);
	}
	cout<<maxPos<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}