#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666;
ll n,x,v[N],qz[N];ll res=6e18;
int main() {
	read(n);read(x);rep(i,1,n)read(v[i]),qz[i]=qz[i-1]+v[i];
	per(a,n,1){
		ll tmp=(n+a)*x+2*(qz[n]-qz[n-a]);ll xs=1;
		for(int p=n;p>=1;p-=a){
			xs+=2;if(tmp+1.0*xs*(qz[p]-(p-a>=0?qz[p-a]:0))>res+100){tmp=res+233;break;}
			tmp+=xs*(qz[p]-(p-a>=0?qz[p-a]:0));
		}
		res=min(res,tmp);
	}
	cout<<res;return 0;
}