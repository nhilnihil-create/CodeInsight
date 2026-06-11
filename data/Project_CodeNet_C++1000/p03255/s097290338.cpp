#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
int n,v;
ll x[200005];
ll calc(int v){
	int l=n-v+1,r=n,t=1;
	ll ans=0;
	for (;r>0;l-=v,r-=v,t++){
		l=max(l,1);
		if (2*INF/max(2*t+1,5)<x[r]-x[l-1]) return 2*INF;
		ans+=1ll*max(2*t+1,5)*(x[r]-x[l-1]);
		if (ans>INF) return ans;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&v);
	for (int i=1;i<=n;i++)
		scanf("%lld",&x[i]),x[i]+=x[i-1];
	ll ans=INF;
	for (int i=1;i<=n;i++)
		ans=min(ans,calc(i)+1ll*i*v);
	printf("%lld\n",ans+1ll*n*v);
}