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
const int N = 255;
int n,cnt[N];int vis[N];//0..23
int s[N],sz,res;
int calc(){
	int mn=24,mx=0,res=0;
	rep(i,0,23)if(vis[i])mx=i;
	per(i,23,0)if(vis[i])mn=i;
	res=mn+24-mx;
	rep(i,0,mx-1)if(vis[i]){
		int j=i+1;while(!vis[j])j++;
		umin(res,j-i);
	}
	return res;
}
int main() {
	read(n);vis[0]++;
	rep(i,1,n){int x;read(x);cnt[x]++;}
	rep(i,0,12)if(cnt[i]>=3){puts("0");return 0;}
	if(cnt[0]){puts("0");return 0;}
	rep(i,1,12)if(cnt[i]==2)vis[i]=vis[24-i]=1;
	else if(cnt[i])s[++sz]=i;
//	if(!sz)res=calc();
	rep(S,0,(1<<sz)-1){
		rep(i,1,sz)vis[S>>i-1&1?s[i]:24-s[i]]++;
		umax(res,calc());
		rep(i,1,sz)vis[S>>i-1&1?s[i]:24-s[i]]--;
	}
	cout<<res;
	return 0;
}
