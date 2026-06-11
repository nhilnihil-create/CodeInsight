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
	vector<int> v(3);
	int k;
	REP(i,3)
		cin>>v[i];
	cin>>k;
	sort(all(v));
	int sum = v[0]+v[1];
	while(k)
	{
		v[2]*=2;
		k--;
	}
	sum+=v[2];
	cout<<sum<<"\n";
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