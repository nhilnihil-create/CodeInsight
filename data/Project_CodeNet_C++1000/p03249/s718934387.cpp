#include<map>
#include<set>
#include<list>
#include<ctime>
#include<cmath>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define rep(i,s,t) for(register int i=s;i<=t;++i)
#define _rep(i,s,t) for(register int i=s;i>=t;--i)
#define Rep(i,s,t) for(register int i=s;i<t;++i)
#define go(x) for(register int e=las[x];e;e=nxt[e])
#define re register
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define pii pair<int,int>
#define ms(f,x) memset(f,x,sizeof f)
#define mc(f,x) memcpy(f,x,sizeof f)
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define gi(x) read(x)
#define gii(x,y) read(x),read(y)
#define giii(x,y,z) read(x),read(y),read(z)
namespace IO{
    #define gc getchar()
    #define pc(x) putchar(x)
    template<typename T>inline void read(T &x){
        x=0;int f=1;char ch=gc;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
        while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=gc;x*=f;return;
    }
    template<typename T>inline void write(T x=0){
        T wr[51];wr[0]=0;if(x<0)pc('-'),x=-x;if(!x)pc(48);
        while(x)wr[++wr[0]]=x%10,x/=10;while(wr[0])pc(48+wr[wr[0]--]);return;
    }
}
using IO::read;
using IO::write;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
const int N=2e5+11;
int n,ans;
int sz[N],x[N],y[N];
ll a[N],sum[N];
struct node{
	ll d;
	int id;
	inline void in(){
		gi(d);
	}
	inline bool operator<(node A)const{
		return d<A.d;
	}
}p[N];
int main(){
	gi(n);
	rep(i,1,n)
		sz[i]=1,sum[i]=0;
	rep(i,1,n)
		p[i].in(),p[i].id=i;
	sort(p+1,p+n+1);
	rep(i,1,n)
		a[i]=p[i].d;
	_rep(i,n,2){
		int pos=lower_bound(a+1,a+n+1,p[i].d-n+2*sz[p[i].id])-a;
		if(a[pos]!=p[i].d-n+2*sz[p[i].id]||p[i].id==p[pos].id){
			puts("-1");
			return 0;
		}
		sz[p[pos].id]+=sz[p[i].id];
		sum[p[pos].id]+=sum[p[i].id]+sz[p[i].id];
		x[++ans]=p[pos].id,y[ans]=p[i].id;
	}
	if(sum[p[1].id]!=a[1]){
		puts("-1");
		return 0;
	}
	rep(i,1,ans)
		printf("%d %d\n",x[i],y[i]);
	return 0;
}