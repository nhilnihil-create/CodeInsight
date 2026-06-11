#include<bits/stdc++.h>
using namespace std;
string s,ss;

int main()
{
	cin>>s>>ss;
	for (int i=s.size()-ss.size();i>=0;i--)
	{
		bool fl=1;
		for (int j=0;j<ss.size();j++)
		{
			if (s[i+j]=='?') 
			continue;
			if (s[i+j]!=ss[j])         
			{
				fl=0;
				break;                
			}
		}
		if (fl)               
		{
		    for (int j=0;j<ss.size();j++) if (s[i+j]=='?') s[i+j]=ss[j];
		    for (int j=0;j<s.size();j++) if (s[j]=='?') s[j]='a';
		    cout <<s;
		    return 0;
		}
	}
	cout <<"UNRESTORABLE";
	return 0;
}