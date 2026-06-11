#include<iostream>
#include<cstdio>
using namespace std;

struct node{
	int u,v,w;
};
node a[65];

int main()
{
	int L,n=1,s=0;
	scanf("%d",&L);
	int t=1,m=--L;
	while(t<=m){
		a[s++]=node{n,n+1,t};
		a[s++]=node{n,n+1,0};
		++n;
		m-=t;	t<<=1;
	}
	int xi=t,p=t/2,k=n-1;
	while(k>=1&&m){
		if(p<=m){
			a[s++]=node{k,n,xi};
			xi+=p;	m-=p;
		}
		p/=2;	--k;
	}
	printf("%d %d\n",n,s);
	for(int i=0;i<s;++i)
		printf("%d %d %d\n",a[i].u,a[i].v,a[i].w);
	
	return 0;
}