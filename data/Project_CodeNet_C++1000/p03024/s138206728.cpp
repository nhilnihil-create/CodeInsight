#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	int n=0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s.at(i)=='x')
		{
			++n;
		}
	}
	if (n<=7)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
}
