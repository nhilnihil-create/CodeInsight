#include <bits/stdc++.h>

using namespace std;

int cnt[25];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	memset(cnt,0,sizeof(cnt));

	int n,t;
	int res = 0;

	cin >> n;

	cnt[0] = 1;

	for(int i=0;i<n;i++)
	{
		cin >> t;
		if(t>12)
		{
			t = 24 - t;
		}
		if(cnt[t]<=1)
		{
			if(cnt[t]==1 && t==12)
			{
				cout << 0 << '\n';
				return 0;
			}
			cnt[t]++;
		}
		else
		{
			cout << 0 << '\n';
			return 0;
		}
	}

	for(int i=0;i<(1<<13);i++)
	{
		vector <int> v;
		//v.push_back(0);
		for(int j=0;j<13;j++)
		{
			int x = j;
			if(cnt[x]==2)
			{
				v.push_back(x);
				v.push_back(24-x);
			}
			else if(cnt[x]==1)
			{
				if(i&(1<<j))
				{
					v.push_back(24-x);
				}
				else
				{
					v.push_back(x);
				}
			}
		}
		sort(v.begin(),v.end());
		int Min = 24;
		for(int j=0;j<v.size();j++)
		{
			for(int k=j+1;k<v.size();k++)
			{
				int d = v[k] - v[j];
				d = min(24-d,d);
				Min = min(Min,d);
			}
		}
		res = max(res,Min);
	}

	cout << res << '\n';

	return 0;
}