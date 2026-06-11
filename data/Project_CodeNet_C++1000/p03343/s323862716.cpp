#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int p=2005;
int n,m,q,a[p],w[p],ans;
int hs(int i,int mid)
{
	int s=0,len=0,sum=0;
	for(int j=1;j<=n;++j)
	if(a[j]<w[i])
	sum+=min(s,max(0,len-m+1)),s=0,len=0;
	else if(a[j]>w[mid])++len;
	else ++len,++s;
	return sum+min(s,max(0,len-m+1));
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)
	scanf("%d",&a[i]),w[i]=a[i];
	sort(w+1,w+n+1);
	ans=w[n]-w[1];
//for(int i=1;i<=n;++i)printf("%d ",w[i]);printf("\n");
	for(int i=1;i+q-1<=n;++i)
{
//printf("i %d\n",i);
	if(hs(i,n)<q)break;
	int l=i+q-1,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(hs(i,mid)<q)l=mid+1;
		else r=mid;
	}
//printf("l %d\n",l);
	ans=min(ans,w[l]-w[i]);
}
	printf("%d",ans);
	return 0;
}
/*
>=w[i],<=w[mid]
*/