#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

const int N=1e6+5;
int n,tl,a[N],mid;
pair<int,int> v[N];

void init()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	v[0].first=-1;
}

void prework()
{
	int i;tl=0;memset(v,0,sizeof(v)); 
	for(i=1;i<n;++i)
		if(a[i]>=a[i+1])
			break;
	if(i<n) v[++tl]=make_pair(a[i+1],1);
}

int inc(int len)
{
//	cout<<len<<"!!!!!!!!!"<<endl;
	if(v[tl].first!=len)
	{
		v[++tl]=make_pair(len,1);
		return true;
	}
	if(tl==len)
	{
		int i;
		for(i=1;i<=tl;++i)
			if(v[i].second!=mid)
				break;
		if(i>tl) return false;
	}
	
	int now=tl;
	if(v[now].second<mid)
	{
		++v[now].second;
		return true;
	}
	while(v[now].first==v[now-1].first+1&&
	v[now-1].second==mid) --now;
	int tfl=(v[now-1].first==v[now].first-1);
	int tt=v[now].first-1;
	while(tl!=now) v[tl--]=make_pair(0,0);
	v[tl--]=make_pair(0,0);
	if(tfl) ++v[now-1].second;
	else v[++tl]=make_pair(tt,1);
	return true;
}

int work()
{
	
	int i;
	for(i=1;i<n;++i)
		if(a[i]>=a[i+1])
			break;
	
	for(++i;i<n;++i)
	{
	//	for(int ii=1;ii<=5;++ii) cout<<v[ii].first<<" "<<v[ii].second<<endl;
	//	cout<<"$$$$$$$"<<endl;
		if(a[i]>=a[i+1])
		{
			while(v[tl].first>a[i+1]) v[tl--]=make_pair(0,0);
			if(!inc(a[i+1])) return false;
		}
	}
	
	return true;
}

int ok()
{
	prework();
	return work();
}

int calc()
{
	int i;
	for(i=1;i<n;++i)
		if(a[i]>=a[i+1])
			return false;
	return true;
}

int main()
{
//	freopen("AGC.in","r",stdin);
//	freopen("AGC.out","w",stdout);
	init();
	if(calc())
	{
		printf("1\n");
		return 0;
	}
	
//	mid=2;cout<<ok()<<endl;
	int l=1,r=n;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ok()) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l+1);
	return 0;
}