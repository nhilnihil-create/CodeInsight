#include<bits/stdc++.h>
#define maxn 100007
#define inf 1000000007
#define ll long long int
using namespace std;

int n;ll c;
ll ww=0;
ll d[maxn],t[maxn],v[maxn],g[maxn];
ll s[maxn],h[maxn],m1[maxn<<2]={0},m2[maxn<<2]={0},le[maxn<<2],ri[maxn<<2];

inline void create(int o,int l,int r)
{
	le[o]=l;ri[o]=r;
	if (l==r)
	{
		m1[o]=h[l]-t[l];
		return ;
	}
	int mid=l+r>>1;
	create(o<<1,l,mid);
	create(o<<1|1,mid+1,r);
	m1[o]=max(m1[o<<1],m1[o<<1|1]);
}

inline void build(int o,int l,int r)
{
	if (l==r)
	{
		m2[o]=h[l];
		return ;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	m2[o]=max(m2[o<<1],m2[o<<1|1]);
}

inline ll query1(int o,int x,int y)
{
	int l=le[o],r=ri[o];
	if (x==l&&y==r) return m1[o];
	int mid=l+r>>1;
	ll ans=0;
	if (y<=mid) ans=query1(o<<1,x,y);
	if (x>mid) ans=query1(o<<1|1,x,y);
	if (x<=mid&&y>mid) ans=max(query1(o<<1,x,mid),query1(o<<1|1,mid+1,y));
	return ans;
}

inline ll query2(int o,int x,int y)
{
	int l=le[o],r=ri[o];
	if (x==l&&y==r) return m2[o];
	int mid=l+r>>1;
	ll ans=0;
	if (y<=mid) ans=query2(o<<1,x,y);
	if (x>mid) ans=query2(o<<1|1,x,y);
	if (x<=mid&&y>mid) ans=max(query2(o<<1,x,mid),query2(o<<1|1,mid+1,y));
	return ans;
}

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
	ll ans=0;
	n=read(),c=read();
	for (int i=1;i<=n;++i) d[i]=read(),t[i]=c-d[i],v[i]=read();
	for (int i=1;i<=n;++i) g[i]=t[n-i+1],ww+=v[i],s[i]=ww-d[i],ans=max(ans,s[i]);ww=0;
	for (int i=n;i>=1;--i) ww+=v[i],h[i]=ww-t[i],ans=max(ans,h[i]);
	create(1,1,n),build(1,1,n);
	for (int i=1;i<n;++i)
	{
		if (d[i]<=t[n]) ans=max(ans,s[i]-d[i]+query2(1,i+1,n));
		else if (d[i]>=t[i+1]) ans=max(ans,s[i]+query1(1,i+1,n));
		else
		{
			int x=n-(upper_bound(g+1,g+n-i+1,d[i])-g)+1;
			ans=max(ans,max(s[i]-d[i]+query2(1,i+1,x),s[i]+query1(1,x+1,n)));
		}
	}
	write(ans);
	return 0;
}