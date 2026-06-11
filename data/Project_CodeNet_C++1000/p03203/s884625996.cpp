#include <bits/stdc++.h>
using namespace std;

set<int> memo[200005];

int main(int argc, char const *argv[])
{
	int h,w,n;
	cin>>h>>w>>n;
	int x,y;
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y;--x;--y;
		memo[x].insert(y);
	}
	int ok=0;
	for (int i = 0; i < h; ++i)
	{
		for (auto v:memo[i])
		{
			if (v<ok)
			{
				cout<<i<<endl;
				return 0;
			}
			else if (v==ok)
			{
				--ok;
				break;
			}
			else
			{
				break;
			}
		}
		++ok;
	}
	cout<<h<<endl;
	return 0;
}
