#include<bits/stdc++.h>
using namespace std;
int n,m,pw[22],ansn,ansm,fs;
pair<pair<int,int>,int> res[222];
int main()
{
	scanf("%d",&n);
	m=1;
	pw[0]=1;
	for (int i=1;i<=20;i++) pw[i]=pw[i-1]*3;
	while(pw[m]<=n) m++;
	m--;ansn=m+2;
	for (int i=0;i<m;i++)
	{
		res[++ansm]=make_pair(make_pair(i,i+1),0);
		res[++ansm]=make_pair(make_pair(i,i+1),pw[i]);
		res[++ansm]=make_pair(make_pair(i,i+1),2*pw[i]);
	}
	fs=n;
	for (int i=0;i<=m;i++)
	{
		int x=fs%3;
		fs/=3;
		if (!x) continue;
		if (x==1)
		{
			res[++ansm]=make_pair(make_pair(i,ansn-1),n-pw[i]);
			n-=pw[i];
		}
		else
		{
			res[++ansm]=make_pair(make_pair(i,ansn-1),n-2*pw[i]);
			res[++ansm]=make_pair(make_pair(i,ansn-1),n-pw[i]);
			n-=pw[i]*2;
		}
	}
	printf("%d %d\n",ansn,ansm);
	for (int i=1;i<=ansm;i++) printf("%d %d %d\n",res[i].first.first+1,res[i].first.second+1,res[i].second);
	return 0;
}