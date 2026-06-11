#include<algorithm>
#include<cstdio>
#define N 2005
using namespace std;
int a[N],l[N],n,o,q,r[N],s[N],t,x;bool w[N],z[N];
inline bool cmp(int u,int v){return a[u]<a[v];}
int main()
{
	scanf("%d%d%d",&n,&o,&q),x=0x7fffffff,w[n+1]=true;
	for(int i=1;i<=n;i++)scanf("%d",a+i),r[i]=n+1;
	for(int i=1,j,k,u;i<=n;i++)
	{
		u=t=0,j=1;
		while(w[j])j++;
		while(j<=n)
		{
			k=j;
			while(!w[k])s[++t]=k++;
			if(k-j<o)t-=k-j;
			else sort(s+t+1-k+j,s+t+1,cmp),t-=o-1;
			j=k;
			while(w[j])j++;
		}
		if(t<q)break;
		sort(s+1,s+t+1,cmp);
		if(a[s[q]]-a[s[1]]<x)x=a[s[q]]-a[s[1]];
		w[s[1]]=true;
	}
	printf("%d\n",x);
	return 0;
}