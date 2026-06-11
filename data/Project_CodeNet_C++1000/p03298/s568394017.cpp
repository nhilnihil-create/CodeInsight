#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	string s;
	cin>>n>>s;
	map<pair<string,string>,int> mp;
	for (int i = 0; i < (1<<n); ++i)
	{
		string l,r;
		for (int j = 0; j < n; ++j)
		{
			if ((i>>j)&1)
			{
				l.push_back(s[j]);
			}
			else
			{
				r.push_back(s[j]);
			}
		}
		++mp[make_pair(l,r)];
	}
	long long ans=0LL;
	for (int i = 0; i < (1<<n); ++i)
	{
		string l,r;
		for (int j = 0; j < n; ++j)
		{
			if ((i>>j)&1)
			{
				r.push_back(s[j+n]);
			}
			else
			{
				l.push_back(s[j+n]);
			}
		}
		reverse(l.begin(), l.end());
		reverse(r.begin(), r.end());
		ans+=mp[make_pair(l,r)];
	}
	cout<<ans<<endl;
	return 0;
}
