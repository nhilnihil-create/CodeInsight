#include<bits/stdc++.h>
//https://atcoder.jp/contests/abc076/tasks/abc076_c?lang=en
using namespace std;
int main()
{
	string s,t;
	cin>>s>>t;
	for(int i=s.size()-t.size();i>=0;--i)
	{
		bool b=1;
		for(int j=0;j<t.size();++j)
		{
			if(s[i+j]=='?')
				continue;
			else if(s[i+j]!=t[j])
			{
				b=0;
				break;
			}
		}
		if(b==1&&!s.size()<t.size())
		{
			string st=s;
			for(int j=i;j<t.size()+i;j++)
				st[j]=t[j-i];
			for(int j=0;j<s.size();j++)
				if(st[j]=='?')
					st[j]='a';
			cout<<st;
			return 0;
		}
	}
	cout<<"UNRESTORABLE";
 
	return 0;
}