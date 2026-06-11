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
	int tC = 0, cnt = 0;
	for(int i=1; i<=n; i+=2)
	{
		cnt = 0;
		for(int j=1; j<=i; j++)
		{
			if((i%j)==0)
				cnt++;
		}
		if(cnt==8)
			tC++;
	}
	cout<<tC<<"\n";
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