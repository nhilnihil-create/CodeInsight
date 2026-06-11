#include <bits/stdc++.h>
using namespace std;
string s,ss;
bool f=0;
int main()
{
	cin>>s>>ss;
	string mn=s,a=s;
	for(int i=0;i<s.size();i++){
		mn[i]='z';
	}
	if(s.size()<ss.size()) {
		cout<<"UNRESTORABLE";
		return 0;
	}
	for (int i=0;i<=s.size()-ss.size();i++)
	{
		bool fl=1;
		for (int j=0;j<ss.size();j++)
		{
			if (s[i+j]=='?') continue;
			if (s[i+j]!=ss[j])
			{
				fl=0;
				break;
			}
		}
		if (fl)
		{
		    for (int j=0;j<ss.size();j++) if (s[i+j]=='?') a[i+j]=ss[j];
		    for (int j=0;j<s.size();j++) if (a[j]=='?') a[j]='a';
		    if(mn>a) mn=a;
		    f=1;
		}
		a=s;
	}
	if(f==1) cout<<mn;
	else cout<<"UNRESTORABLE";
}