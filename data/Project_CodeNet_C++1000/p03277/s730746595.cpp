#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=500010, inf=1e9;
int n, N;
int a[maxn], b[maxn], tr[maxn];

template<typename T>
inline void read(T &k)
{
	int f=1; k=0; char c=getchar();
	while(c<'0' || c>'9') c=='-'&&(f=-1), c=getchar();
	while(c<='9' && c>='0') k=k*10+c-'0', c=getchar();
	k*=f;
}

inline void add(int x){for(;x<=2*n+1;x+=x&-x) tr[x]++;}

inline int query(int x){int sum=0; for(;x;x-=x&-x) sum+=tr[x]; return sum;}

inline ll check(int mid)
{
	int sum=0; ll ans=0;
	for(int i=1;i<=2*n+1;i++) tr[i]=0;
	add(n+1);
	for(int i=1;i<=n;i++)
	{
		sum+=(a[i]<mid)?1:(-1);
		ans+=query(sum+n);
		add(sum+n+1);
	}
	return ans;
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i]), b[i]=a[i];
	sort(b+1, b+1+n); N=unique(b+1, b+1+n)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1, b+1+N, a[i])-b;
	int l=1, r=N;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)*2<=(1ll*n*(n+1)>>1)) l=mid;
		else r=mid-1;
	}
	printf("%d\n", b[l]);
}