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
	string s;
	cin >> s;
	int ans=-INF;
	for(int i=0; i<n; i++)	{
		int cnt[27];
		int c=0;
		memset(cnt,0,sizeof(cnt));
		for(int j=0; j<=i; j++)	{
			cnt[s[j]-'a']++;
		}
		for(int j=i+1; j<n; j++)	{
			if(cnt[s[j]-'a'])	{c++; cnt[s[j]-'a']=0;}
		}
		ans=max(ans,c);
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