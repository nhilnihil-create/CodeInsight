#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=5005;
int n,A,B,a[N];
ll f[N],v1[N],v2[N];
ll mn[N*4],tg[N*4];
struct TR1{
	int t[N];
	void change(int x){
		for (;x<=n;x+=x&(-x)) t[x]++;
	}
	int ask(int x){
		int ans=0;
		for (;x;x-=x&(-x)) ans+=t[x];
		return ans;
	}
}T1;
void build(int k,int l,int r){
	mn[k]=1ll<<60; tg[k]=0;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void pushdown(int k){
	if (!tg[k]) return;
	tg[k*2]+=tg[k]; tg[k*2+1]+=tg[k];
	mn[k*2]+=tg[k]; mn[k*2+1]+=tg[k];
	tg[k]=0;
}
void change(int k,int l,int r,int x,int y,ll v){
	if (l==x&&r==y){
		tg[k]+=v;
		mn[k]+=v;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else{
		change(k*2,l,mid,x,mid,v);
		change(k*2+1,mid+1,r,mid+1,y,v);
	}
	mn[k]=min(mn[k*2],mn[k*2+1]);
}
void change(int k,int l,int r,int x,ll v){
	if (l==r){	
		mn[k]=v;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,v);
	else change(k*2+1,mid+1,r,x,v);
	mn[k]=min(mn[k*2],mn[k*2+1]);
}
ll ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return mn[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return min(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
}
int main(){
	scanf("%d%d%d",&n,&A,&B);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n){
		v1[i]=1ll*A*(i-1)+1ll*T1.ask(a[i])*(B-A);
		v2[i]=1ll*A*(n-a[i])+1ll*B*(a[i]-1)-v1[i];
		T1.change(a[i]);
	}
	ll ans=1ll<<60;
	build(1,1,n);
	For(i,1,n) f[i]=v1[i];
	For(i,1,n){
		f[i]=min(f[i],ask(1,1,n,1,a[i])+1ll*(i-1)*A);
		change(1,1,n,a[i],n,B-A);
		change(1,1,n,a[i],f[i]-1ll*i*A);
	}
	For(i,1,n)
		ans=min(ans,f[i]+v2[i]);
	printf("%lld\n",ans);
}