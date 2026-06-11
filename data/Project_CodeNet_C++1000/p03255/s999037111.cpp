#include<vector>
#include<cstdio>
#include<queue>
#include<algorithm>
#define MN 410001
#define ll long long
using namespace std;

int n,m,w[MN],c[MN];
long long f[MN],ans=9e18;
long long sqr(long long x){return x*x;}
inline void Min(long long &x,long long v){if(x>v) x=v;}
inline ll work(int p){
	ll ans=0;
	for (int i=n,j=0,k=0;i;i--){
		ans+=1LL*c[k]*w[i];
		j++;
		if (j==p) j=0,k++;
	}
	ans+=1LL*p*m;
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	c[0]=5;
	for (int i=1;i<=n;i++) c[i]=i*2+3;
	int l=1,r=n,mid1,mid2;
	while(l<r-10){
		int u=(r-l)/3;
		mid1=l+u;mid2=r-u;
		if (work(mid1)<work(mid2)) r=mid2;else l=mid1;
	}
	l-=10;r+=10;
	if (l<1) l=1;if (r>n) r=n;
	for (int i=l;i<=r;i++) Min(ans,work(i));
	printf("%lld\n",ans+1LL*n*m);
}