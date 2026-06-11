#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int n,k,q;
int a[2004];
int b[2004];
int c[2004],pc;
int mint;
int ans=INF;
void init()
{
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=-INF,a[n+1]=-INF;
	return;
}
void check()
{
	int last=0;			//最后一个不可删去数字的位置 
	pc=0;
	for(int i=1;i<=n+1;i++)
	{
		if(a[i]<mint)
		{
			if(i==last+1)
			{
				last=i;
				continue;
			}
//			cout<<"A"<<last+1<<" "<<i-1<<endl;
			sort(b+last+1,b+i);
			for(int j=last+1;j<=i-k;j++)
				c[++pc]=b[j];
			last=i;
		}
/*		for(int i=1;i<=n;i++)
			cout<<b[i]<<" ";
		cout<<endl;*/
		
	}
//	cout<<endl;
//	cout<<pc<<endl;
	if(pc<q) return;
	sort(c+1,c+1+pc);
/*	for(int i=1;i<=pc;i++)
		cout<<c[i]<<" ";
	cout<<endl;*/
	ans=min(ans,c[q]-mint);
	return;
}
int main()
{
	init();
	for(int i=1;i<=n;i++)
	{
//		cout<<"test"<<i<<":"<<endl;
		mint=a[i];
		for(int i=1;i<=n;i++) b[i]=a[i];
		check();
//		cout<<endl;
	}
	printf("%d\n",ans);
	return 0;
}