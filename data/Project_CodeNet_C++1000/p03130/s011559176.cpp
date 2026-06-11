#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int a,memo[4]={};
	for (int i = 0; i < 6; ++i)
	{
		cin>>a;--a;
		++memo[a];
	}
	int cnt=0;
	for (int i = 0; i < 4; ++i)
	{
		if (memo[i]%2==1)
		{
			++cnt;
		}
	}
	if (cnt==0||cnt==2)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
}
