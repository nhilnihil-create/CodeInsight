#include<bits/stdc++.h>
using namespace std;

int n,m;

struct az
{
	int p;
	int y;
	int cnt;
}q[100005];

struct za
{
	int p;
	int y;
    int x;
}l[100005];

bool cmp(za a, za b)
{
	if(a.p==b.p) return a.y < b.y;
	return a.p < b.p;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	   scanf("%d%d",&q[i].p,&q[i].y),l[i].x=i,l[i].p=q[i].p,l[i].y=q[i].y;
	sort(l+1,l+1+m,cmp);
	int now = 0 ;
	for(int i=1;i<=m;++i)
	{
		if(l[i].p != l[i-1].p) now=0;
		q[l[i].x].cnt=++now;
	}
	for(int i=1;i<=m;++i)
	{
		int s=q[i].p;
		int ls=0;
		while(s)
		{
			s/=10;
			++ls;
		}
		for(int j=1;j<=6-ls;++j)
		   cout<<0;
		cout<<q[i].p;
		s=q[i].cnt;
		ls=0;
		while(s)
		{
			s/=10;
			++ls;
		}
		for(int j=1;j<=6-ls;++j)
		   cout<<0;
		cout<<q[i].cnt;
		cout<<endl;
	}
	return 0;
 } 