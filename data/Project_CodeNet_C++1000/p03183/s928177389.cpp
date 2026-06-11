#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;
const int MAXN=100010;

struct node{
	int w,s,v;
	bool operator<(const node &rhs)const{
		return w+s<rhs.w+rhs.s;
	}
}a[MAXN];
long long f[MAXN];

int main(){
	int n;scanf("%d",&n);
	int mx=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].w,&a[i].s,&a[i].v);
		mx=max(a[i].s+a[i].w,mx);
	}
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=a[i].s;j>=0;j--)
			f[a[i].w+j]=max(f[a[i].w+j],f[j]+a[i].v);
	long long ans=0;
	for(int i=0;i<=mx;i++)
		ans=max(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}