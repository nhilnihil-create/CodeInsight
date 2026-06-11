#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
#define INF INT32_MAX
#define INFL INT64_MAX
using namespace std;

void solve()	{
	int n,m;
	cin >> n >> m;
	string s[n];
	for(int i=0; i<n; i++)	cin >> s[i];
	for(int i=0; i<n; i++)	{
		for(int j=0; j<m; j++)	{
			int b=0;
			if(s[i][j]!='#')	{
				if(i-1>=0 && j-1>=0 && s[i-1][j-1]=='#')	b++;
				if(i-1>=0 && s[i-1][j]=='#')	b++;
				if(j-1>=0 && s[i][j-1]=='#')	b++;
				if(i-1>=0 && j+1<m && s[i-1][j+1]=='#')	b++;
				if(j+1<m && s[i][j+1]=='#')	b++;
				if(i+1<n && j+1<m && s[i+1][j+1]=='#')	b++;
				if(i+1<n && s[i+1][j]=='#')	b++;
				if(i+1<n && j-1>=0 && s[i+1][j-1]=='#')	b++;
				cout << b;
			}
			else	cout << '#';
		}
		cout << endl;
	}
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