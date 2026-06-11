//#include"bits/stdc++.h"
#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,c,i,j,maxx;
long long x[100200],v[100200],val1[100200],val2[100200],go[100200],back[100200];
int main()
{
while(cin>>n>>c)
{
		maxx=0;
	for(i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&v[i]);
	for(i=1;i<=n;i++)
	{
		val1[i]=val1[i-1]+v[i];
		go[i]=max(go[i-1],val1[i]-x[i]);
		maxx=max(maxx,go[i]);
	}
		
	for(i=n;i>=1;i--)
	{
		val2[i]=val2[i+1]+v[i];
		back[i]=max(back[i+1],val2[i]-(c-x[i]));
		maxx=max(maxx,back[i]);
	}
	for(i=1;i<=n;i++)
		maxx=max(maxx,val1[i]-2*x[i]+back[i+1]);
	for(i=n;i>=1;i--)
		maxx=max(maxx,val2[i]-2*(c-x[i])+go[i-1]);
	cout<<maxx<<endl;
}
}