#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	long long n;
	cin>>n;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			n--;
			if(n<=0)
			{
				cout<<'1';
				return 0;
			}
		}
		else
		{
			cout<<s[i];
			return 0;
		}
	}
}