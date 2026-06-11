#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int tree[1000100],n,a[100100],val[100100],maxn=-1e9,minn=1e9;
void build(int t,int l,int r){
	tree[t]=0;
	if(l==r)return;
	int mid=(l+r)/2;
	build(t*2,l,mid);
	build(t*2+1,mid+1,r);
}
void modify(int t,int l,int r,int pos){
	if(l==r){
		tree[t]++;
		return;
	}
	int mid=(l+r)/2;
	if(pos<=mid)modify(t*2,l,mid,pos);
	else modify(t*2+1,mid+1,r,pos);
	tree[t]=tree[t*2]+tree[t*2+1];
}
int query(int t,int l,int r,int L,int R){
	if(L>r||l>R)return 0;
	if(L<=l&&r<=R)return tree[t];
	int mid=(l+r)/2;
	return query(t*2,l,mid,L,R)+query(t*2+1,mid+1,r,L,R);
}
bool check(int now){
	build(1,0,n+n);
	for(int i=1;i<=n;i++)
		if(a[i]<now)val[i]=-1;else val[i]=1;
	for(int i=1;i<=n;i++)val[i]+=val[i-1];
	int res=0;
	modify(1,0,n+n,n);
	for(int i=1;i<=n;i++){
		res+=query(1,0,n+n,0,val[i]+n);
		modify(1,0,n+n,val[i]+n);
	}
	return res>=(int)((n*(n+1)/2)/2);
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),maxn=max(maxn,a[i]),minn=min(minn,a[i]);
	int L=minn,R=maxn,ans;
	while(L<=R){
		int mid=(L+R)/2;
		if(check(mid))ans=mid,L=mid+1;
		else R=mid-1;
	}
	printf("%lld\n",ans);
}