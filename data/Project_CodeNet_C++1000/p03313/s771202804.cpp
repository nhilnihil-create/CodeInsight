#include<algorithm>
#include<iostream>
#include<cstdio>

using namespace std;

struct pp{int a1,a2;} mx1[300001],mx2[300001],c[4];

int a[300001],lastans=0,n;

bool cmp(pp o,pp p) {return o.a1<p.a1;}

void dfs(int o)
{
	if(mx1[o].a1) return;
	mx1[o].a1=a[o];mx1[o].a2=o;
	mx2[o].a1=-1;mx2[o].a2=-1;
	for(int i=1;i<=n;i++)
		if(o&(1<<(i-1)))
		{
			int yu=o^(1<<(i-1));
			dfs(yu);
			c[0]=mx1[o];c[1]=mx2[o];
			c[2]=mx1[yu];c[3]=mx2[yu];
			sort(c,c+4,cmp);
			mx1[o]=c[3];
			int j=2;
			while((j>=0)&&(c[j].a2==c[3].a2)) j--;
			mx2[o]=c[j];
		}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<1<<n;i++) scanf("%d",&a[i]);
	dfs((1<<n)-1);
	for(int i=1;i<1<<n;i++)
	{
		lastans=max(lastans,mx1[i].a1+mx2[i].a1);
		printf("%d\n",lastans);
	}
	return 0;
}