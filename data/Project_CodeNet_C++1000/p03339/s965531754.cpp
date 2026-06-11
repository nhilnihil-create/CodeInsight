#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int e[n+1];
	int w[n+1];
	e[0]=0;
	w[0]=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='E')
		{
			e[i+1]=e[i]+1;
			w[i+1]=w[i];
		}
		else
		{
			e[i+1]=e[i];
			w[i+1]=w[i]+1;
		}
	}
	long long ans=9999999999;
	for(int i=1;i<=n;i++)
	{
		if((w[i-1]+e[n]-e[i])<ans)
		ans=w[i-1]+e[n]-e[i];
	}
	cout<<ans;
 } 