/**Bismillahir Rahmanir Raheem
    Author:Refatul Fahad**/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define sz(s)  (int)s.size()
#define all(s)  s.begin(),s.end()
const int N = 1e5 + 5;
const ll M = (ll)1e9 + 7;
const double pi=2*acos(0.0);
const double esp=1e-9;
int Set(int N,int pos) {
    return N=N | (1<<pos);
}
int reset(int N,int pos) {
    return N= N & ~(1<<pos);
}
bool check(int N,int pos) {
    return (bool)(N & (1<<pos));
}

int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

vi adj[N];
bool vis[N];
int edcnt[N],deg[N];

void dfs(int node) {
    vis[node]=true;
    for(int x:adj[node]) {
        edcnt[x]=max(edcnt[x],edcnt[node]+1);
        --deg[x];
        if(!deg[x]) {
            dfs(x);
        }
    }
}
int main() {

    //IOS;
    /// freopen("input.txt","r",stdin);
    /// freopen("output.txt","w",stdout);

    int test=1;
    //cin>>test;
    for(int cs=1; cs<=test; ++cs) {
        int n,m,ans=0;
        cin>>n>>m;
        for(int i=1; i<=m; ++i) {
            int x,y;
            cin>>x>>y;
            adj[x].pb(y);
            ++deg[y];
        }
        for(int i=1; i<=n; ++i) {
            if(!vis[i]&&!deg[i]) {
                dfs(i);
            }
        }
        for(int i=1; i<=n; ++i) {
            ans=max(ans,edcnt[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

