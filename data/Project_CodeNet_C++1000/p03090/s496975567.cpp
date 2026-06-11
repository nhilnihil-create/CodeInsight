#include <bits/stdc++.h> 
 
using namespace std; 

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	set <pair<int,int>> res;
	cin >> n;

	if(n%2==0)
	{
		int val = n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j || j==val)
				{
					continue;
				}
				if(i < j)
				{
					res.insert(make_pair(i,j));
				}
				else
				{
					res.insert(make_pair(j,i));
				}
			}
			val--;
		}
	}
	else
	{
		int val = n - 1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j || j==val)
				{
					continue;
				}
				if(i < j)
				{
					res.insert(make_pair(i,j));
				}
				else
				{
					res.insert(make_pair(j,i));
				}
			}
			val--;
		}
	}

	cout << res.size() << '\n';

	for(auto it : res)
	{
		cout << it.first << ' ' << it.second << '\n';
	}

    return 0;
}