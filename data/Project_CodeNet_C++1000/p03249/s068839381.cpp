#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int inf=1e9;
const ll Inf=1e18;
const int N=1e5+10;
ll gi() {
    ll x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
template<typename T> void chkmax(T &a,T b) { a<b?a=b:0; };
template<typename T> void chkmin(T &a,T b) { a>b?a=b:0; };
int n,id[N],siz[N];
ll d[N];
map<ll,int> M;
pii e[N];
int tot=0;
vector<int> E[N];
bool cmp(int a,int b) { return d[a]<d[b]; }
ll dfs(int u,int dep) {
    ll ret=0;
    for(int v:E[u]) ret+=dfs(v,dep+1);
    return ret+dep;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) d[i]=gi(),id[i]=i;
    sort(id+1,id+n+1,cmp);sort(d+1,d+n+1);
    for(int i=1;i<=n;i++) M[d[i]]=i;
    for(int i=1;i<=n;i++) siz[i]=1;
    for(int i=n;i>1;i--) {
        int p=M[d[i]-2*(n-siz[i])+n];
        if(!p||p>=i) return puts("-1"),0;
        e[++tot]=mp(id[p],id[i]);E[p].pb(i);siz[p]+=siz[i];
    }
    if(dfs(1,0)!=d[1]) puts("-1");
    else for(int i=1;i<=tot;i++) printf("%d %d\n",e[i].fi,e[i].se);
    return 0;
}
