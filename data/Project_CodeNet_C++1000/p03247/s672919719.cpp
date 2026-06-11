#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x[2001],y[2001];
void proc(bool f)
{
	int k=38;
	vector<int> v;
	int sum=0;
	if(f)v.push_back(1),sum=1;
	for(int s=0;s<=k;s++)v.push_back(1ll<<s),sum+=1ll<<s;
	int N=(int)v.size();
	printf("%lld\n",N);
	for(int i:v)printf("%lld ",i);
	puts("");
	for(int i=0;i<n;i++)
	{
		bool p[51],sel[51];
		int s=sum,t=N-1;
		memset(p,-1,sizeof p);
		memset(sel,0,sizeof sel);
		while(s>x[i]+y[i])
		{
			while(s-2*v[t]<x[i]+y[i])t--;
			s-=2*v[t];
			p[t]=0;
		}
		int totx=0;
		for(int j=0;j<N;j++)
			if(p[j])sel[j]=1,totx+=v[j];
		t=N-1;
		while(totx>x[i])
		{
			if(p[t]&&totx-v[t]>=x[i])totx-=v[t],sel[t]=0;
			else if(!p[t]&&totx-v[t]>=x[i])totx-=v[t],sel[t]=1;
			t--;
		}
		for(int j=0;j<N;j++)putchar(p[j]?sel[j]?'R':'U':sel[j]?'L':'D');
		puts("");
	}
}
main()
{
	scanf("%lld",&n);
	int q[2]={0,0},lim=0;
	for(int i=0;i<n;i++)scanf("%lld%lld",x+i,y+i),q[(x[i]+y[i])&1]++,lim=max(lim,abs(x[i]+y[i]));
	if(q[0]&&q[1])return puts("-1"),0;
	if(lim&1)proc(0);
	else proc(1);
}
