#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

#define int ll
#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define lowbit(x) x&(-x)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10;

int a[MAXN],sum[MAXN];
struct bitree {
	int c[MAXN],n;
	void add(int x,int d) {
		while(x<=n) {
			c[x]+=d;
			x+=lowbit(x);
		}
	}
	int ask(int x) {
		int ans=0;
		while(x) {
			ans+=c[x];
			x-=lowbit(x);
		}
		return ans;
	}
} s;

int n;

int b[MAXN];

bool check(int mid) {
	sum[0]=0;s.n=0;
	memset(s.c,0,sizeof(s.c));
	REP(i,1,n) sum[i]=(a[i]<=mid?-1:1);
	REP(i,1,n) sum[i]+=sum[i-1];
	REP(i,0,n) b[++s.n]=sum[i];
	sort(b+1,b+s.n+1);
	s.n=unique(b+1,b+s.n+1)-b-1;
	REP(i,0,n) sum[i]=lower_bound(b+1,b+s.n+1,sum[i])-b;
	long long ans=0; 
	REP(i,0,n) ans += s.ask(sum[i]),s.add(sum[i],1);
	return ans*2>=1ll*n*(n+1)/2;
}
signed main() {
	n=read();s.n=n;
	REP(i,1,n) a[i]=read();

	int l=1,r=1e9,ans;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1,ans=mid;
	}

	printf("%lld\n",ans);
	return 0;
}

