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
	string prev, curr;
	cin>>prev;
	set<string> st = {prev};
	for(int i=0; i<n-1; i++)
	{
		cin>>curr;
		if(st.count(curr) || prev[prev.length()-1]!=curr[0])
		{
			cout<<"No\n";
			return;
		}
		st.insert(curr);
		prev = curr;
	}
	cout<<"Yes\n";
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