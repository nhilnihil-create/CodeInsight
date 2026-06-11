#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<map>
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,len[200001],ans,F;
map<int,int> Q;
inline int check(int lim)
{
	Q.clear();
	for(register int i=2;i<=n;++i)
		if(len[i]<=len[i-1])
		{
			while(!Q.empty())
			{
				int zone=Q.rbegin()->first;
				if(zone>len[i])
					Q.erase(zone);
				else
					break;
			}
			int mem=len[i];
			while(Q[mem]+1==lim)
			{
				Q.erase(mem);
				--mem;
			}
			if(!mem)
				return 0;
			Q[mem]+=1;
		}
	return 1;
}
int main()
{
	n=read();
	for(register int i=1;i<=n;++i)
	{
		len[i]=read();
		if(len[i]<=len[i-1])
			F=1;
	}
	if(!F)
	{
		puts("1");
		return 0;
	}
	int l=2,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
			ans=mid,r=mid-1;
		else
			l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}