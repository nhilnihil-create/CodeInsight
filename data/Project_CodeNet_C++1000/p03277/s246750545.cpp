#include<bits/stdc++.h>
#define ll long long
#define db double
#define lowbit(p) (p&(-p))
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define A first
#define B second
using namespace std;
void read(int &x){
	x=0; char c=getchar(); int p=1;
	for (;c<48;c=getchar())if (c=='-')p=-1;
	for (;c>47;c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x*=p;
}
void read(ll &x){
	x=0; char c=getchar(); int p=1;
	for (;c<48;c=getchar())if (c=='-')p=-1;
	for (;c>47;c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x*=p;
}
void Min(int &x,int y){
	if (x>y)x=y;
}
void Max(int &x,int y){
	if (x<y)x=y;
}
void Min(ll &x,ll y){
	if (x>y)x=y;
}
void Max(ll &x,ll y){
	if (x<y)x=y;
}
/*
中位数的中位数.
同样考虑二分答案?


*/
#define M 200005
int a[M],sum[M],n,L,R;
struct Reimu{
#define ls (p<<1)
#define rs (p<<1|1)
	int f[M<<3];
	void build(int l,int r,int p){
		f[p]=0;
		if (l==r){
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
	void upd(int l,int r,int x,int p){
		f[p]++;
		if (l==r){
			return ;
		}
		int mid=(l+r)>>1;
		if (x<=mid)upd(l,mid,x,ls);
		else upd(mid+1,r,x,rs);
	}
	int qu(int l,int r,int x,int y,int p){
		if (l==x&&r==y)return f[p];
		int mid=(l+r)>>1;
		if (y<=mid)return qu(l,mid,x,y,ls);
		if (x>mid) return qu(mid+1,r,x,y,rs);
		return qu(l,mid,x,mid,ls)+qu(mid+1,r,mid+1,y,rs);
	}
}T;
ll chk(int x){
//	printf("------%d-------\n",x);
	ll res=0;
	int i;
	T.build(L,R,1);
	T.upd(L,R,0,1);
	for (i=1;i<=n;i++){
		sum[i]=sum[i-1];
		if (a[i]<=x)sum[i]++;
		else sum[i]--;
		res+=T.qu(L,R,L,sum[i]-1,1);
//		printf("%d ",T.qu(L,R,L,sum[i]-1,1));
		T.upd(L,R,sum[i],1);
	}
//	printf("\n");
//	printf("res=%lld\n",res);
	return res;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen("1.in","r",stdin);
	read(n);
	int i,l,r,mid,res;
	L=-n-5;
	R=n+5;
	for (i=1;i<=n;i++){
		read(a[i]);
	}
	l=1; r=1e9; res=0;
//	printf("%lld\n",(ll)n*(n+1)/2/2+1);
	for (;l<=r;){
		mid=(l+r)>>1;
//		printf("%d %lld\n",mid,chk(mid));
		if (chk(mid)>=((ll)n*(n+1)/2/2+1)){
			r=mid-1;
			res=mid;
		}				
		else {
			l=mid+1;
		}
	}
	printf("%d\n",res);
	return 0;
}