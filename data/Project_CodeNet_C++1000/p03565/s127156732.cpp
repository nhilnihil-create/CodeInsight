#include<bits/stdc++.h>
using namespace std;
bool ling(string a,string aa)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!='?' && a[i]!=aa[i])
		return false;
	}
	return true;
}
int main()
{
	string s,t,b="~";
	cin>>s>>t;
	for(int i=0;i<=(int)s.size()-(int)t.size();i++)
	{
		string z=s.substr(i,t.size());
		if(ling(z,t)){
			string w=s;
			for(int j=i;j<i+t.size();j++)
			{
				w[j]=t[j-i];
			}
			for(int j=0;j<i;j++)
			{
				if(w[j]=='?')
				w[j]='a';
			}
			for(int j=i+t.size();j<w.size();j++)
			{
				if(w[j]=='?')
				w[j]='a';
			}
			b=min(b,w);
		}
	}
	if(b=="~")
	cout<<"UNRESTORABLE\n";
	else
	cout<<b<<endl;
}
