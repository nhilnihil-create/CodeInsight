#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,x,i,u=0;
	cin>>a>>b;
	string s;
	cin>>s;
	x=s.size();
	if(x!=(a+b+1) || s[a]!='-' )
	{
		cout<<"No"<<endl;
		return 0;
	}
	for(i=0;i<x;i++)
	{
		if(s[i]=='-')
		{
			u++;
		}
	}
	if(u>1)
	{
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
}