/*
 * =template=.cpp
 * Copyright (C) 2017 hzw <hzw@huzhenweideMacBook.local>
 *
 * Distributed under terms of the MIT license.
 */
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<signal.h>
#include<unistd.h>
#define FR first
#define SC second
#define MP make_pair
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define pb push_back
#define ws wss
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
void read(int &x)
{
	char ch;int fu=1;
	while ((ch=getchar())<=32);
	x=0;
	if (ch=='-') fu=-1;else x=ch-48;
	while ((ch=getchar())>32) x=x*10+ch-48;
	x*=fu;
}
template<class T> void upmax(T &a,T b) { if (a<b) a=b;}
template<class T> void upmin(T &a,T b) { if (a>b) a=b;}

//---------template--------------
const int N=1000100,p=998244353;
int c[7123],bit[7777];
LL f[7777];
int n,a,b;
void C(int i) { for (;i<=n;i+=i&-i) bit[i]++;}
int  Q(int i) { int res=0;for (;i;i-=i&-i) res+=bit[i];return res;}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) bit[j]=0;
		f[i]=1LL<<60;
		for (int j=i-1,k=0;j>=0;j--)
		{
		//	printf("%d %d\n",i,j);
			int l=Q(c[j]);
			if (c[j]<c[i]&&l+k==i-j-1) { f[i]=min(f[i],f[j]+1LL*l*b+1LL*k*a);}
			if (j>0) C(c[j]);
			if (c[j]>c[i]) k++;
		}
	}
	LL ans=1LL<<60;
	for (int i=1;i<=n;i++)
	{
		int flag=0;
//		printf("%lld ",f[i]);
		for (int j=i+1;j<=n;j++)
			if (c[j]>c[i]) { flag=1;break;}
		if (flag) continue;
		ans=min(ans,f[i]+1LL*(n-i)*b);
	}
	cout<<ans<<endl;
}
