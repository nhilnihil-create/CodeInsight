#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,a,b;
	cin>>n>>b>>a;
	if (a+b-1>n||(long long)a*b<(long long)n)
	{
		cout<<"-1\n";
		return 0;
	}
	vector<int> ans[(n+a-1)/a];
	int now=n,r=b;
	for (int i = (n+a-1)/a-1; i >= 0; --i)
	{
		--r;
		for (int j = 0; j < a; ++j)
		{
			if (now>r)
			{
				ans[i].push_back(now);
				--now;
			}
			else
			{
				break;
			}
		}
		if (now<r)
		{
			break;
		}
	}
	if (now>0)
	{
		for (int i = 1; i <= now; ++i)
		{
			if (i==1)
			{
				cout<<1;
			}
			else
			{
				cout<<" "<<i;
			}
		}
		for (int i = 0; i < (n+a-1)/a; ++i)
		{
			for (auto v:ans[i])
			{
				cout<<" "<<v;
			}
		}
		return 0;
	}
	int f=1;
	for (int i = 0; i < (n+a-1)/a; ++i)
	{
		for (auto v:ans[i])
		{
			if (f)
			{
				cout<<v;
				f=0;
			}
			else
			{
				cout<<" "<<v;
			}
		}
	}
	return 0;
}
