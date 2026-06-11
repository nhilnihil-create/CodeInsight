#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
const ll MAX = 1e5 + 5;

int main(void)
{
	string s;
	cin >> s;
	ll n = s.length();
	vector <ll> v, ans[MAX];
	if(s[0] != '1' || s[n - 1] != '0')
	{
		cout << "-1" << endl;
		return 0;
	}
	for(int i = 0; i < n - 1; i++)
	{
		if(n - i - 2 >= 0 && s[i] != s[n - i - 2])
		{
			cout << "-1" << endl;
			return 0;
		}
	}
	ll k = 0;
	for(int i = 0; i < n - 1; i++)
	{
		if(s[i] == '1')
		{
			for(int j = 0; j < v.size(); j++)
			{
				ans[k].pb(i + 1);
				ans[k].pb(v[j]);
				k++;
			}
			v.clear();
			v.pb(i + 1);
		}
		else
			v.pb(i + 1);
	}
	for(int i = 0; i < v.size(); i++)
	{
		ans[k].pb(n);
		ans[k].pb(v[i]);
		k++;
	}

	for(int i = 0; i < k; i++)
		cout << ans[i][0] << " " << ans[i][1] << endl;


 	



	return 0;
}