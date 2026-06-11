#include<bits/stdc++.h>
#define maxn 200007
#define ll long long int
using namespace std;

ll a[maxn];
ll f[maxn];

inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

inline void writ(ll x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) writ(x/10);
	putchar(x%10+'0');
}
inline void write(ll x){writ(x);putchar('\n');}

int main()
{
	int t=0;
	int k=read();
	f[0]=1;
	for (int i=1;i<=20;++i) f[i]=9*f[i-1];
	for (int i=1;i<=9;++i) a[++t]=i;
	for (int i=1;i<=9;++i) a[++t]=i*10ll+9ll;
	for (int i=1;i<=19;++i) a[++t]=i*100ll+99ll;
	for (int i=2;i<=29;++i) a[++t]=i*1000ll+999ll;
	for (int i=3;i<=39;++i) a[++t]=i*10000ll+9999ll;
	for (int i=4;i<=49;++i) a[++t]=i*100000ll+99999ll;
	for (int i=5;i<=59;++i) a[++t]=i*1000000ll+999999ll;
	for (int i=6;i<=69;++i) a[++t]=i*10000000ll+9999999ll;
	for (int i=7;i<=79;++i) a[++t]=i*100000000ll+99999999ll;
	for (int i=8;i<=89;++i) a[++t]=i*1000000000ll+999999999ll;
	for (int i=9;i<=99;++i) a[++t]=i*10000000000ll+9999999999ll;
	for (int i=10;i<=99;++i) a[++t]=i*100000000000ll+99999999999ll;
	for (int i=10;i<=109;++i) a[++t]=i*1000000000000ll+999999999999ll;
	for (int i=11;i<=99;++i) a[++t]=i*10000000000000ll+9999999999999ll;
	for (int i=1;i<=k;++i) write(a[i]);
	return 0;
}