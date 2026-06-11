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
	int n, m, x;
	cin>>n>>m>>x;
	int num;
	set<int> st;
	REP(i,m)
	{
		cin>>num;
		st.insert(num);
	}	
	int cost1 = 0, cost2 = 0;
	for(int i = x+1; i<=n; i++)
	{
		if(st.count(i))
			cost1++;
	}
	for(int i=x-1; i>0; i--)
	{
		if(st.count(i))
			cost2++;
	}
	cout<<min(cost1, cost2);
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