#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	int n=s.size();
	if (s[0]=='0'||s[n-1]=='1')
	{
		cout<<"-1\n";
		return 0;
	}
	int f=1;
	for (int i = 0; i < n/2; ++i)
	{
		if (s[i]!=s[n-i-2])
		{
			f=0;
		}
	}
	if (f==0)
	{
		cout<<"-1\n";
		return 0;
	}
	int now=n;
	for (int i = n-1; i > 0; --i)
	{
		cout<<i<<" "<<now<<endl;
		if (s[i-1]=='1')
		{
			now=i;
		}
	}
	return 0;
}
