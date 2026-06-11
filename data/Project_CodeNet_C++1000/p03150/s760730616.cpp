#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i=0,a=0;
	string s,e="keyence";
	cin>>s;
	for(int t=0;t<s.size();t++)
	{
		if(s[t]!=e[i])
		{ 
			break;
		}
		else
		{
			i++;
			a++;
		}
	}
	i=6;
	for(int t=s.size()-1;t>=0;t--)
	{
		if(s[t]!=e[i])
		{ 
			break;
		}
		else
		{
			i--;
			a++;
		}
	}
	//cout<<a<<" ";
	if(a>=7)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}