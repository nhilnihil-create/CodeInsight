#include<bits/stdc++.h>
using namespace std;
int main ()
{
	string s,s0,s1,ans="~";
	cin>>s>>s1;
	s0=s;
	if(s.size()<s1.size())
	{
		cout<<"UNRESTORABLE";
		return 0;
	}
	for(int t=s.size()-s1.size();t>=0;t--)
    {
    	bool ok=1;
    	for(int i=t;i<t+s1.size();i++)
    	{
    		if(s[i]==s1[i-t]||s[i]=='?')
    		{
    			s0[i]=s1[i-t];
			}
			else
			{
				ok=0;
				break;
			}
		}
		if(ok)
		{
			for(int i=0;i<s.size();i++)
			{
				if(s0[i]=='?')
				{
					s0[i]='a';
				}
			}
			ans=min(ans,s0);
		}
		s0=s;
	}
	if(ans=="~")
	{
		cout<<"UNRESTORABLE";
		return 0;
	}
	cout<<ans;
	return 0;
}