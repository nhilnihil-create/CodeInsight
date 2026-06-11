#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 5050;
int n,p[N],pos[N],a,b,mx[N][N];
ll f[N][N];
int main() {
	read(n);read(a);read(b);rep(i,1,n)read(p[i]),pos[p[i]]=i;
	rep(i,1,n)rep(j,i,n)mx[i][j]=max(mx[i][j-1],p[j]);
	rep(i,0,n)rep(j,0,n)f[i][j]=1e16;
	f[0][0]=0;
	rep(i,0,n-1)rep(j,0,n)if(f[i][j]<1e16){
		if(pos[i+1]<=j)umin(f[i+1][j],f[i][j]+a);
		else if(i+1==mx[j+1][pos[i+1]])umin(f[i+1][j],f[i][j]);
		else{
			umin(f[i+1][j],f[i][j]+b);
			umin(f[i+1][pos[i+1]],f[i][j]);
		}
	}
	ll res=1e16;rep(i,0,n)umin(res,f[n][i]);
	cout<<res;
	return 0;
}
