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
	string s;
	cin>>s;
	int maxPos = 0;
	int cnt = 0;
	set<char> st;
	st.insert('A');
	st.insert('C');
	st.insert('G');
	st.insert('T');
	for(int i=0; i<s.length(); i++)
	{
		if(st.count(s[i]))
			cnt++;
		else
		{
			maxPos = max(maxPos, cnt);
			cnt = 0;
		}
	}
	maxPos = max(maxPos, cnt);
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