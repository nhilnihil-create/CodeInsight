#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;}
    return false;
}

template<typename T>
struct TreeDiameter{
    vector<T> dp;
    vector<vector<pair<int,T>>> G;
    TreeDiameter(int n):dp(n),G(n){}
    void add_edge(int u,int v,T c){
        G[u].emplace_back(v,c);
        G[v].emplace_back(u,c);
    }
    void dfs(int v,int p,int &s){
        if (p<0) dp[v]=T(0);
        if (dp[s]<dp[v]) s=v;
        for (auto e:G[v]){
            int u=e.first;
            if (u==p) continue;
            dp[u]=dp[v]+e.second;
            dfs(u,v,s);
        }
    }
    Pii endPoints(){
        int s=0;
        dfs(s,-1,s);
        int t=s;
        dfs(t,-1,t);
        return Pii{s,t};
    }
    T build(){
        int t=endPoints().second;
        return dp[t];
    }
    vector<T> distance(int v){
        dfs(v,-1,v);
        return dp;
    }
    vector<T> farthest(){
        int t=endPoints().second;
        auto ds=dp;
        auto dt=distance(t);
        rep(i,ds.size()) chmax(ds[i],dt[i]);
        return ds;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    TreeDiameter<int> TD(N);
    rep(i,N-1){
        int a,b; cin >> a >> b;
        TD.add_edge(--a,--b,1);
    }
    int d=TD.build();
    if (d%3!=1) cout << "First" << endl;
    else cout << "Second" << endl;
}