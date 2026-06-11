#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<bitset>
#include<stack>
#include<cassert>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define mem(x,y) memset(x,y,sizeof x)
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
const int INF=2e9;
const db eps=1e-12;
template<typename T>
inline void read(T &x) {
	x=0; int f=1; char ch=getchar();
	while( (ch<'0' || ch>'9') && ch!='-') ch=getchar(); if(ch=='-') {f=-1; ch=getchar();}
	while(ch>='0' && ch <='9') x=x*10+ch-'0',ch=getchar();
	x*=f;
}
//==========================head template==========================
const int N=100010;
ll d[N];
int n;
map<ll,int> key;
pli seq[N];
int fa[N],sz[N];
ll ret[N];
signed main() {
  read(n);
  for(int i=1;i<=n;i++) read(d[i]);
  for(int i=1;i<=n;i++) key[d[i]]=i;
  for(int i=1;i<=n;i++) seq[i]=mp(d[i],i);
  sort(seq+1,seq+n+1); reverse(seq+1,seq+n+1);
  for(int i=1;i<=n;i++) sz[i]=1;
  for(int i=1;i<n;i++) {
    int u=seq[i].S;
    ll delta=d[u]+sz[u]-(n-sz[u]);
    //printf("%lld %d\n",delta,u);
    if(!key.count(delta)) {puts("-1"); return 0;}
    fa[u]=key[delta];
    sz[fa[u]]+=sz[u];
    ret[fa[u]]+=ret[u]+sz[u];
  }
  if(seq[n].F!=ret[seq[n].S]) {
    puts("-1"); return 0;
  }
  for(int i=1;i<=n;i++)
    if(fa[i]) {printf("%d %d\n",i,fa[i]);}
  return 0;
}
