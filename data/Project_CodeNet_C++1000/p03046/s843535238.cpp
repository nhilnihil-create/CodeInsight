#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#include"bits/stdc++.h"
using namespace std;

int32_t main()
{
	int m,k;
	cin>>m>>k;
	if(m==0)
	{
		if(k==0){puts("0 0");}
		else puts("-1");
		return 0;
	}
	if(m==1)
	{
		if(k==0){puts("0 0 1 1");}
		else puts("-1");
		return 0;
	}
	
	if(k>=(1<<m)){puts("-1");return 0;}
	
	for(int i=0;i<(1<<m);i++)
	{
		if(i!=k)cout<<i<<' ';
	}
	cout<<k<<' ';
	for(int i=(1<<m)-1;i>=0;i--)
	{
		if(i!=k)cout<<i<<' ';
	}
	cout<<k<<' ';
}