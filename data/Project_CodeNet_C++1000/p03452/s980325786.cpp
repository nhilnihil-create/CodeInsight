#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <vector>
#define CL(a) memset(a,0,sizeof(a))
#define cl(a,b) memset(a,(b),sizeof(a))
#define For(i,a,b) for(int i=a;i<=b;i++)
#define _for(i,a,b) for(int i=a;i<b;i++)
#define LL long long 
using namespace std;
const int maxn = 2e5 + 100;
int pre[maxn];
#define v val 
long long val[maxn];
int Find(int x)
{
	if(x==pre[x])
	{
		return x;
	}
	else 
	{
		int tmp = pre[x];
		pre[x] = Find(pre[x]);
		v[x]+=v[tmp];
		return pre[x];
	}
}

bool link(int x,int y,long long d)
{
	int fx = Find(x);
	int fy = Find(y);
	if(fx==fy)
	{
		return v[y]==v[x]+d;
	}
	pre[fy] = fx;
	v[fy] = d+v[x]-v[y];
	return true;
}
int main()
{
	int m,n;
	int L,R; 
	long long D;
	bool flag;
	while(cin>>n>>m)
	{
		flag = true;
		for(int i=0;i<maxn;i++)
			pre[i] = i,val[i] = 0;
		
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%lld",&L,&R,&D);
			if(!flag) continue;
			if(!link(L,R,D)) flag = false;
		}
		//for(int i=1;i<=n;i++)
		//	cout<<val[i]<<" ";cout<<endl;
		for(int i=1;flag&&i<=n;i++)
			if(val[i]>1e9) flag = false;
		if(flag) printf("Yes\n");
		else printf("No\n");
	
	
	}


        

	return 0;
}