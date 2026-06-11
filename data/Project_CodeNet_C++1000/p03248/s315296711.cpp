#include<bits/stdc++.h>
using namespace std;
string st;
int l,x;
int main()
{
	cin>>st;
	l=st.size();
	st=" "+st;
	if(!(st[1]-'0'))
	{
		puts("-1");
		return 0;
	}
	if(st[l]-'0')
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<l;i++)
	if(st[i]!=st[l-i])
	{
		puts("-1");
		return 0;
	}
	x=1;
	for(int i=1;i<l;i++)
	{
		printf("%d %d\n",i+1,x);
		if(st[i]-'0')x=i+1;
	}
	return 0;
}