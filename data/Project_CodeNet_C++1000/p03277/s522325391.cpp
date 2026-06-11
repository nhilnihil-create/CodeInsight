#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <bitset>
 
using namespace std;
 
#define IL inline
#define RE register
#define DB double
#define RT return
#define LL long long
#define INF 1e9+10
#define MAXN 200010
#define FOR(i,a,b) for(RE LL i=(a); i<=(b); i++)
#define FOR2(i,a,b) for(RE LL i=(a); i>=(b); i--)
#define reset(a) memset(a,0,sizeof(a))
#define reset2(a) memset(a,127,sizeof(a)) 
#define lson(x) x<<1
#define rson(x) x<<1|1
#define pq priority_queue
#define P pair<LL,LL>
 
IL LL read()
{
	RE LL x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
	RT x*f;
} 

LL n,a[MAXN],s[MAXN],tree[MAXN*4],b[MAXN];

IL LL query(RE LL x)
{
	RE LL ans=0;
	while(x)
	{
		ans+=tree[x];
		x-=x&-x;
	}
	RT ans;
}

IL void update(RE LL x)
{
	while(x<=3*n)
	{
		tree[x]++;
		x+=x&-x; 
	}
}

IL LL js(RE LL x)
{
	reset(tree);
	s[0]=0;
	RE LL minn=2*n;
	FOR(i,1,n)
	{
		if(a[i]>=x) s[i]=s[i-1]+1;
		else s[i]=s[i-1]-1;
		minn=min(minn,s[i]); 
	}
	minn=-minn;
	minn++;
	RE LL ans=0;
	FOR(i,1,n)
	{
		ans+=query(s[i]+minn);
		update(s[i]+minn);
		if(s[i]>=0) ans++;
	}
	RT ans;
}

IL bool pd(RE LL x)
{
	RE LL num=js(x);
	if(num>=n*(n+1)/2-num) RT 1;
	RT 0;	
} 

int main()
{
	n=read();
	FOR(i,1,n)
	{
		a[i]=read();
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	RE LL i=1,j=n+1;
	while(i<j)
	{
		RE LL mid=(i+j)>>1ll;
		if(pd(b[mid])) i=mid+1;
		else j=mid; 
	}
	cout<<b[i-1];
	RT 0;
}