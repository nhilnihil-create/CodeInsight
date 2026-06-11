#include<bits/stdc++.h>
#define N 100005
#define ll long long
#define pii pair<ll,int>
#define mp make_pair
using namespace std;

ll n,size[N];
int e[N][2];
pii a[N];

inline ll read()
{
	ll ans=0,f=1;char c=getchar();
	while(c>'9'||c<'0') {if(c=='-') f=-1ll;c=getchar();}
	while(c>='0'&&c<='9') ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans*f;
}

int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=mp(read(),i),size[i]=1;
	sort(a+1,a+1+n);
	for(int i=n;i>1;i--)
	{
		ll cur=a[i].first-n+2*size[i];
		int l=1,r=i-1;
		while(l<r)
		{
			int mid=l+r>>1;
			if(a[mid].first<cur) l=mid+1;
			else r=mid;
		}
		if(a[l].first!=cur) return puts("-1"),0;
		e[i][0]=a[i].second;
		e[i][1]=a[l].second;
		size[l]+=size[i];
	}
	for(int i=2;i<=n;++i) a[1].first-=size[i];
	if(a[1].first) return puts("-1"),0;
	for(int i=2;i<=n;++i) printf("%d %d\n",e[i][0],e[i][1]);
}
