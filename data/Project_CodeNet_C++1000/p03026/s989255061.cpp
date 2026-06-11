#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 1e4+10;
int n,a[N],d[N],ans[N],flag[N];
vector<int>e[N];

int main(){
	n=read();
	FOR(i,1,n){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	poly vec;
	For(i,1,n){
		d[i]=siz(e[i]);
		if (d[i]==1) vec.pb(i);
	}
	For(i,1,n) a[i]=read();
	sort(a+1,a+1+n);
	ll sum=0;
	FOR(i,1,n){
		int u=vec.back();vec.pop_back();
		flag[u]=1,ans[u]=a[i];
		for (auto v:e[u]) if (!flag[v]){
			--d[v],sum+=a[i];
			if (d[v]==1) vec.pb(v);
		}
	}
	For(i,1,n) if (!flag[i]) ans[i]=a[n];
	printf("%lld\n",sum);
	For(i,1,n) printf("%d ",ans[i]);
}