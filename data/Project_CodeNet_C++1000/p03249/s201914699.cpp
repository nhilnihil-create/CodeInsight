//W4P3R
#include<bits/stdc++.h>
#define inf 1e9
#define eps 1e-6
#define re register ll 
#define FOR(i,a,b) for(re i=a;i<=b;i++)
#define REP(i,a,b) for(re i=a;i>=b;i--)
#define mp make_pair
#define pb push_back
#define pf push_front
#define pa pair<ll,ll>
#define fr first
#define sd second
#define Z(x) (x>=mod?x-mod:x)
#define lowbit(x) (x&(-x))
#define N 100010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
    char ch=getchar();
    ll s=0,w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
    return s*w;
}
ll n;
ll D[N],sz[N],s=0;
set<pa>S;
vector<ll>e[N];
vector<pa>ans; 
void dfs(ll u,ll father,ll d)
{
	s+=d;
	for(ll v:e[u])if(v!=father)dfs(v,u,d+1);
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    n=read();
    FOR(i,1,n){D[i]=read();S.insert(mp(D[i],i));}
    ll t=n-1;
    while(t--)
    {
    	ll x=(*(--S.end())).sd;S.erase(S.lower_bound(mp(D[x],x)));
    	sz[x]++;
    	ll v=D[x]+2*sz[x]-n;
    	ll y=(*S.lower_bound(mp(v,0))).sd;
    	//cout<<"WTF:"<<x<<" "<<D[x]<<" "<<sz[x]<<" "<<v<<" "<<y<<" "<<D[y]<<endl;
    	if(D[y]!=v){puts("-1");return 0;}
    	e[x].pb(y),e[y].pb(x);sz[y]+=sz[x];
    	ans.pb(mp(x,y));
    }
    dfs(1,0,0);
    if(s==D[1]){for(auto tmp:ans)printf("%lld %lld\n",tmp.fr,tmp.sd);}
    else puts("-1");
    return 0;
}