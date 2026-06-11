#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<0<<endl;
	string s;
	cin>>s;
	if (s=="Vacant")
	{
		return 0;
	}
	int ok=0,ng=n+1;
	while (ng-ok>1)
	{
		int mid=(ok+ng)/2;
		cout<<mid<<endl;
		string t;
		cin>>t;
		if (t=="Vacant")
		{
			return 0;
		}
		if (mid%2==0)
		{
			if (s==t)
			{
				ok=mid;
			}
			else
			{
				ng=mid;
			}
		}
		else
		{
			if (s==t)
			{
				ng=mid;
			}
			else
			{
				ok=mid;
			}
		}
	}
	cout<<ok<<endl;
	cin>>s;
	if (s=="Vacant")
	{
		return 0;
	}
	return 0;
}
