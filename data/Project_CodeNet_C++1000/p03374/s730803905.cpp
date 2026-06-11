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
#define M 100005 
ll c,v[M],x[M],sum[M],l[M],r[M],res,L[M],R[M];
int n;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen("1.in","r",stdin);
	read(n); read(c);
	int i;
	for (i=1;i<=n;i++){
		read(x[i]); read(v[i]);
	}
	x[n+1]=c;
	for (i=1;i<=n;i++){
		sum[i]=sum[i-1]+v[i];
		l[i]=max(l[i-1],sum[i]-x[i]);
		L[i]=max(L[i-1],sum[i]-2*x[i]);
	}
	for (i=n;i>=1;i--){
		r[i]=max(r[i+1],sum[n]-sum[i-1]-(c-x[i]));
		R[i]=max(R[i+1],sum[n]-sum[i-1]-2*(c-x[i]));
	}	
	for (i=1;i<=n;i++){
		Max(res,l[i]+R[i+1]);
		Max(res,L[i]+r[i+1]);	
	}
//	printf("%lld %lld  %lld\n",x[n],c-x[n],sum[n])
	Max(res,sum[n]-x[n]);
	Max(res,sum[n]-c+x[1]);
	printf("%lld\n",res);
	return 0;
}