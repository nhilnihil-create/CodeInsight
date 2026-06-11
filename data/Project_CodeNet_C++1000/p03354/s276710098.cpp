#include<bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

#define ll long long int
#define ld long double
#define loop(i, n) for (int i = 0; i < n; i++)
#define loops(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define deb(x) cout<< #x << '=' << x <<endl
#define MOD 1000000007
const int N = 1e5 + 5;
int n,m;
vector<int> b;
vector<int> adj[N];
int a[N];
int vis[N];
map<int,int> cnt;
void dfs(int u){
    vis[u] = 1;
    cnt[u]++;
    cnt[a[u]]++;
    b.pb(u);
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v);        
        }
    }
}
void init(){
    for(auto x : b){
        if(cnt[x] == 2){
            a[x] = x;
        }
    }
    cnt.clear();
    b.clear();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < m; i++){
        int x , y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            init();
        }
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == i){
            ans++;
        }
    }
    cout<<ans;
}