#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX 2000005
#define MOD 1000000007
#define MOD2 998244353
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define vi vector<ll>
#define vp vector<pii>
#define all(v) v.begin(),v.end()
#define sz(x) (ll)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(ll i=a;i<b;++i)
#define ROF(i,a,b) for(ll i=a;i>=b;--i)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
typedef long long ll;
using namespace std;
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

ll mexp(ll a, ll b){
    ll ans=1;
    a%=MOD;
    while(b){
        if(b&1) ans=ans*a%MOD;
        b>>=1;
        a=a*a%MOD;
    }
    return ans;
}

const int N = 100005;

vector<int>g[N];
ll d[N],ssize[N];
ll ck[N],ckd;
map<ll,int>f;

void dfs(int u, int p){
    for(int v:g[u]){
        if(v==p){
            continue;
        }
        ck[v]=ck[u]+1;
        dfs(v,u);
    }
    ckd+=ck[u];
}

void dfs2(int u,int p){
    for(int v:g[u]){
        if(v==p){
            continue;
        }
        cout<<u<<" "<<v<<endl;
        dfs2(v,u);
    }
}

int main(){
    IOS

    int n;
    cin>>n;
    FOR(i,1,n+1){
        cin>>d[i];
        f[d[i]]=i;
        ssize[i]=1;
    }
    sort(d+1,d+n+1);
    ROF(i,n,2){
        int u=f[d[i]];
        ll dd=n-2*ssize[u];
        if(dd<=0){
            cout<<-1;
            return 0;
        }
        dd=d[i]-dd;
        if(f[dd]==0){
            cout<<-1;
            return 0;
        }
        int v=f[dd];
        cerr<<u<<" "<<v<<endl;
        ssize[v]+=ssize[u];
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0);
    if(f[ckd]!=1){
        cout<<-1;
    }
    else{
        dfs2(1,0);
    }

    cerr<<"Time: "<<1.0/CLOCKS_PER_SEC<<" ms"<<endl;
    return 0;
}