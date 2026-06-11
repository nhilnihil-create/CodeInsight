#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

	const ll MOD = 1e9+7;
int main()
{
	int n;
	string s;
	cin >> n >> s;
	vector<vector<int>> v(n,vector<int>(26));
	for(int i = 0;i<n;i++)
	{
		v[i][s[i]-'a']++;
	}
	for(int i = n-1;i>0;i--)
	{
		for(int j=0;j<26;j++)
		{
			(v[i-1][j]+=v[i][j])%=MOD;
		}
	}
	ll ans = 0;
	for(int i = 0;i<n;i++)
	{
		ll add = 1;
		for(int j = 0;j<26;j++)
		{
			if(s[i]==j+'a')continue;
			(add*=v[i][j]+1)%=MOD;
		}
		(ans+=add)%=MOD;
	}
	cout<<ans<<endl;
	
	return 0;
}