#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	char s;
	int r=0,b=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>s;
		if (s=='R')
		{
			++r;
		}
		else
		{
			++b;
		}
	}
	if (r>b)
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	return 0;
}
