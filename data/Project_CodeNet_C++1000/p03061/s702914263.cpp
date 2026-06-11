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
	vector<int> v(n+2);
	vector<int> left(n+2, 0);
	vector<int> right(n+2, 0);
	for(int i=1; i<=n; i++)
		cin>>v[i];
	for(int i=1; i<=n; i++)
	{
		left[i] = __gcd(left[i-1], v[i]);
	}
	for(int i=n; i>=1; i--)
	{
		right[i] = __gcd(right[i+1], v[i]);
	}
	int maxPos = 1;
	for(int i=1; i<=n; i++)
	{
		int lrGCD = __gcd(left[i-1], right[i+1]);
		maxPos = max(lrGCD, maxPos);
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