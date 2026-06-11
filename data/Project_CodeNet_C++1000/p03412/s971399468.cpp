#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 200005
using namespace std;
typedef long long ll;
int n;
int a[maxn],b[maxn],c[maxn],d[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int j=1;j<=n;j++)
		scanf("%d",&b[j]);

	int ans=0;

	for(int i=0;i<=29;i++)
	{
		int maxx=(1<<(i+1))-1;

		for(int j=1;j<=n;j++)
			c[j]=(a[j]&maxx),d[j]=(b[j]&maxx);

//		cerr<<"its c ";
//		for(int j=1;j<=n;j++)
//			cerr<<c[j]<<" ";
//		cerr<<endl;
//		cerr<<"its d ";
//		for(int j=1;j<=n;j++)
//			cerr<<d[j]<<" ";
//		cerr<<endl;

		sort(d+1,d+1+n);

		ll cnt=0;
		for(int j=1;j<=n;j++)
		{
			if((1<<i)&c[j])
			{
				int temp=(1<<(i+1))-c[j];
				cnt+=(lower_bound(d+1,d+1+n,temp)-d)-1;
//				cerr<<"its "<<(lower_bound(d+1,d+1+n,temp)-d)-1<<endl;
				temp=3*(1<<i)-c[j];
				cnt+=(n-(lower_bound(d+1,d+1+n,temp)-d)+1);
//				cerr<<"its "<<temp<<" "<<(lower_bound(d+1,d+1+n,temp)-d)<<endl;
			}
			else
			{
				int temp=(1<<i)-c[j];
				int nl=(lower_bound(d+1,d+1+n,temp)-d);
				temp=(1<<(i+1))-c[j];
				int nr=(lower_bound(d+1,d+1+n,temp)-d)-1;
				cnt+=(nr-nl+1);
			}
//			cerr<<cnt<<" ";
		}
//		cerr<<endl;
		if(cnt&1)
			ans|=(1<<i);
	}
	printf("%d\n",ans);
}
