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
	ll n, m;
	cin>>n>>m;
	ll l ,r;
	vector<ll> range(n+2, 0);
	REP(i, m)
	{
		cin>>l>>r;
		range[l]++;
		range[r+1]--;
	}
	int cnt = 0;
	for(int i=1; i<=n; i++)
	{
		range[i]+=range[i-1];
		if(range[i]==m) cnt++;
	}
	cout<<cnt<<"\n";
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