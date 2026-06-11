#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s,t,s1;
	int ans=-1000;
	cin>>s>>t;
	if (t.size()>s.size())
	{
		cout <<"UNRESTORABLE";
		return 0;
	}
	for(int j=0;j<s.size()-t.size()+1;j++)
	{
		int f=0;
		s1=s.substr(j,t.size());
		for(int i=0;i<t.size();i++)
		{
			if(s1[i]!=t[i])
			f=1;
		}
		if(f==0)
		{
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='?') s[i]='a';
			}
			cout<<s;
			return 0;
		}
	}
	for(int i=s.size()-t.size();i>=0;i--)
	{
		int F=1;
		if(t[0]==s[i]||s[i]=='?')
		{
			F=0;
			for(int j=i;j<i+t.size();j++)
			{
				if(!(s[j]==t[j-i]||s[j]=='?'))
				{
					F=1;
					break;
				}	
			}
		}
		if(F==0)
		{
			ans=i;
			break;
		}
	}
	if(ans==-1000)
	{
		cout<<"UNRESTORABLE";
		return 0;
	}
	for(int i=ans;i<ans+t.size();i++)
	{
		s[i]=t[i-ans];
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='?') s[i]='a';
	}
	cout<<s;
	return 0;
}