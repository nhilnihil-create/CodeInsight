#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#define MAXN 100005
#define LL long long
using namespace std;

int n, l=1e9, r, ans, a[MAXN], b[MAXN], c[MAXN];
LL t[MAXN*2];

void add(int x, int y)
{
	for(; x<=2e5; x+=(x&-x)) t[x]+=y;
}

LL ask(int x)
{
	LL sum=0;
	for(; x; x-=(x&-x)) sum+=t[x];
	return sum;
}

bool check(int mid)
{
	LL num=0;
	memset(t, 0, sizeof(t));
	for(int i=1; i<=n; i++)
	{
		if(a[i]<mid) c[i]=-1;
		else c[i]=1;
		c[i]=c[i]+c[i-1];
	}
	for(int i=0; i<=n; i++)
	{
		num+=ask(c[i]+1e5);
		add(c[i]+1e5, 1);
	}
	return num>=1LL*(n+1)*n/4;
}


int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &a[i]);
		b[i]=a[i];
	}
	sort(b+1, b+n+1);
	l=1; r=n; 
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(b[mid])) ans=mid, l=mid+1;
		else r=mid-1;
	}
	printf("%d\n", b[ans]); 
}
 