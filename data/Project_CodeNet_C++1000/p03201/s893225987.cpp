#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int tb(int x)
{
	int res = 2;
	while(res<x)res *= 2;
	res = res - x;
	if(res==0)res = x;
	return res;
}
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i<n;i++)cin >> a[i];
	map<int,int> mp;
	for(int i = 0;i<n;i++)mp[a[i]]++;
	sort(a.rbegin(),a.rend());
	int ans = 0;
	for(int i = 0;i<n;++i)
	{
		if(mp[a[i]]==0)continue;
		int now = tb(a[i]);
		if(a[i]==now)
		{
			if(mp[a[i]]>1)
			{
				ans++;
				mp[now]-=2;
			}
			continue;
		}
		if(mp[now]>0)
		{
			mp[now]--;
			ans++;
			mp[a[i]]--;
		}
	}
	cout << ans << endl;
}
