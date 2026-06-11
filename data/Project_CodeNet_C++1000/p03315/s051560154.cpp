#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int x=0;
	cin>>s;
	for (int i=0; i<s.size(); i++)
	{
		if (s[i]=='+')
		{
			x++;
		}
		if (s[i]=='-')
		{
			x--;
		}
	}
	cout<<x;
	return 0;
}