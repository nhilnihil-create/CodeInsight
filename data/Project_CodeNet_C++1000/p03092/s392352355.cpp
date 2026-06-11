#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mem(x,v) memset(x,v,sizeof(x))
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define gc getchar
#define pc putchar
#define fi first
#define se second
inline ll read(){
    ll x=0,f=1;char c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
inline void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);pc('\n');}
inline void wri(ll x){write(x);pc(' ');}
const int maxn = 5500;
ll c[maxn],f[maxn],ans;
int n,a[maxn];
ll A,B,C;
#define lson (o<<1)
#define rson (o<<1|1)
#define mid ((l+r)>>1)
ll tag[maxn<<2],T[maxn<<2];
ll query(int o,int l,int r,int x,int y){
	if(l==x && r==y) return T[o];
	if(y<=mid) return query(lson,l,mid,x,y) + tag[o]; else
	if(mid+1<=x) return query(rson,mid+1,r,x,y) + tag[o]; else
	return min(query(lson,l,mid,x,mid),query(rson,mid+1,r,mid+1,y)) + tag[o];
}
void modify(int o,int l,int r,int x,int y,ll v){
	if(l==x && r==y){
		T[o] += v;
		tag[o] += v;
		return ;
	}
	if(y<=mid) modify(lson,l,mid,x,y,v); else
	if(mid+1<=x) modify(rson,mid+1,r,x,y,v); else
	modify(lson,l,mid,x,mid,v),modify(rson,mid+1,r,mid+1,y,v);
	T[o] = min(T[lson],T[rson]) + tag[o];
}
void M(int o,int l,int r,int x,ll v){
	if(l==r){
		T[o] = v;
		return ;
	}
	if(x<=mid) M(lson,l,mid,x,v - tag[o]); else
			   M(rson,mid+1,r,x,v - tag[o]);
	T[o] = min(T[lson],T[rson]) + tag[o];
}
int main(){
    n = read(),A = read(),B = read();
    Rep(i,1,n) a[i] = read();
    if(A>B){
        swap(A,B);
        reverse(a+1,a+1+n);
        Rep(i,1,n) a[i] = n-a[i]+1;
    }
    C = min(A,B);
    ans = 1ll << 60;
    memset(T,0x3f,sizeof(T));
    memset(tag,0,sizeof(tag));
    Rep(i,1,n){//A是右移，B是左移 
    	f[i] = min((i - 1) * A,query(1,1,n,1,a[i]) + i * C - C);
        if(a[i]+1<=n) modify(1,1,n,a[i]+1,n,B-C);
        M(1,1,n,a[i],f[i]-i*C);
        ans = min(ans,f[i] + B * (n - i));
    }writeln(ans);
    return 0;
}