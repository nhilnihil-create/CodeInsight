#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
using namespace std;

void solve()	{
	int n;
	cin >> n;
	int pt=0,px=0,py=0,f=0;
	for(int i=0; i<n; i++)	{
		int t,x,y;
		cin >> t >> x >> y;
		int T = t-pt;
		int X = abs(x-px);
		int Y = abs(y-py);
		pt=t;
		px=x;
		py=y;
		if(X+Y>T || (T-(X+Y))&1)		{
			f=1;	
			//cout << X << " " << Y << " " << T << " " << t << endl;
		}
	}
	if(f)	cout << "No\n";
	else cout << "Yes\n";
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