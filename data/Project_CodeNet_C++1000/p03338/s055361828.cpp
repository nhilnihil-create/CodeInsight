#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n,c=0,temp=0;
	cin>>n;
	string s;
	cin>>s;
	string s1,s2;
	for(int i=1;i<n;i++)
	{
		s1=s.substr(0,i);
		s2=s.substr(i,n-1);
		int a[26],b[26];
		memset(a,0,sizeof(a));
	    memset(b,0,sizeof(b));
		for(int i=0;i<s1.size();i++)
	{
		int x=s1[i]-'a';
		a[x]++;
	}
	for(int i=0;i<s2.size();i++)
	{
		int y=s2[i]-'a';
		b[y]++;
	}
	for(int i=0;i<26;i++)
	{
		if(a[i]>0 && b[i]>0)
		{
			c++;
		}
	}
	temp=max(temp,c);
	c=0;
	}
	cout<<temp<<endl;
	return 0;
}