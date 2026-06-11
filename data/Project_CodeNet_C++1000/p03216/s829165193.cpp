#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n;string s;
	int q;
	cin>>n;
	cin>>s;
	cin>>q;
	while(q--)
	{
		ll d=0,m=0,dm=0,dmc=0;
		int k;
		scanf("%d",&k);
		for(int i=0;i<k;i++)
		{
			if(s[i]=='D')
			{
				d++;
			}
			else if(s[i]=='M')
			{
				dm+=d;m++;
			}
			else if(s[i]=='C')
			{
				dmc+=dm;
			}
		}
		for(int i=k;i<n;i++)
		{
			if(s[i-k]=='D')
			{
				d--;dm-=m;
			}
			else if(s[i-k]=='M')
			{
				m--;
			}
			if(s[i]=='D')
			{
				d++;
			}
			else if(s[i]=='M')
			{
				dm+=d;m++;
			}
			else if(s[i]=='C')
			{
				dmc+=dm;
			}
		}
		printf("%lld\n",dmc);
	}
 } 
