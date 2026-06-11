#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,t,s;
	cin>>s1>>t;
	bool ok=0;
	s=string(s1.size(),'z');
	if(s1.size()<t.size())
	{
		cout<<"UNRESTORABLE";
		return 0;
	}
	for(int i=0;i<=s1.size()-t.size();i++)
	{
		bool flag=1;
		for(int j=0;j<t.size();j++)
		{
			if(s1[i+j]!='?'&&s1[i+j]!=t[j])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			ok=1;
			string ts=s1;
			for(int j=0;j<t.size();j++)
				ts[i+j]=t[j];
			for(int j=0;j<ts.size();j++)
				if(ts[j]=='?')
					ts[j]='a';
			if(ts<s)
				s=ts;
		}
	}
	if(ok)
		cout<<s;
	else
		cout<<"UNRESTORABLE";
	return 0;
}