#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define pll pair<ll,ll>
#define plii pair<ll,pii>
#define vi vector<int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mx 100001
#define eps 0.00000000001
#define mod 1000000007
#define pi acos(-1)
#define inf 100000000
#define loop(i,b,n) for(int i=b;i<n;++i)
#define rev_loop(i,b,n) for(int i=b;i>=n;--i)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int N_MAX=1e5;
vector<vector<pll> >g(N_MAX);
vector<ll>color(N_MAX,0);


void dfs(ll u,ll p=-1){
    for(auto v:g[u]){
        if(v.ff==p)continue;
        if(v.ss%2)
            color[v.ff]=1-color[u];
        else
        color[v.ff]=color[u];
        dfs(v.ff,u);
    }
}
int main(){
    fio;
    ll n;
    cin >>n;
    for (int i = 0; i < n - 1; ++i) {
        ll u,v,w;
    cin >>u>>v>>w;
    u--;
    v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
        cout <<color[i]<<endl;
    }
    return 0;
}
