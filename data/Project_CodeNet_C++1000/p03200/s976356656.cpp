#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define evn(x) (!((x)&1))
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
using namespace std;

void solve()	{
	string s;
	cin >> s;
	ll w=0;
	ll ans=0;
	for(int i=0; i<s.size(); i++)	{
		if(s[i]=='W')	{
			ans+=(i-w);
			w++;
		}
	}
	cout << ans << endl;
}

int main()	
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin >> t;
	for(int i=1; i<=t; i++)	{
		solve();
	}
	return 0;
}
