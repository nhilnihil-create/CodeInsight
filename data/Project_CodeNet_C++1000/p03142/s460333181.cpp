// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<ll> vec;
typedef vector<P> pvec;
typedef vector<vector<ll>> vvec;
typedef vector<vector<P>> pvvec;
typedef priority_queue<ll> PQI;
typedef priority_queue<P> PQP;
typedef priority_queue<ll,vector<ll>,greater<ll>> PQIG;
typedef priority_queue<P,vector<P>,greater<P>> PQPG;
const vector<int> dx = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
const int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30); // 1073741824
const int INF = (1LL << 60); // 1152921504606846976
const double EPS = (1 >> 30);
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template< typename T1, typename T2 > istream &operator>>(istream &is, pair< T1, T2 > &p) { is >> p.first >> p.second; return is; }

int max_len;
struct DirectedGraph
{
    int V;
    vvec G; // 有向グラフ
    vvec rG; // 逆向きの有向グラフ

    vector<bool> used;
    vec vs;
    vec depth;

    vec cmp;
    DirectedGraph(int V) : V(V),
        G(vvec(V)),
        rG(vvec(V)),
        cmp(vec(V)),
        depth(vec(V))
        {}
    
    void add_edge(int a,int b){ // a->b
        G[a].pb(b);
        rG[b].pb(a);
    }

    void dfs(int now){
        used[now]=true; // 探索済
        for(auto next:G[now]) if(!used[next]) dfs(next);
        vs.pb(now);
    }

    int rdfs(int now,int k){
        int ret=0;
        used[now]=true;
        cmp[now]=k;
        for(auto next: rG[now]){
            if(!used[next]) rdfs(next,k);
            chmax(depth[now],depth[next]+1); 
        }
        return ret+1;
    }

    int scc_num=-1;
    int scc(){
        used=vector<bool>(V,false);
        vs.clear();
        rep(v,V) if(!used[v]) dfs(v);

        used=vector<bool>(V,false);
        scc_num=0;
        for(int i=vs.size()-1;i>=0;i--){
            if(!used[vs[i]]){
                chmax(max_len,rdfs(vs[i],scc_num++));
            }
        }
        return scc_num; // 強連結成分の個数を返却
    }

    DirectedGraph generateTopologicalGraph()
    {
        DirectedGraph newgraph(scc_num);
        rep(s,V){
            for(auto next:G[s]){
                if(cmp[s]!=cmp[next]){
                    newgraph.add_edge(cmp[s],cmp[next]);
                }
            }
        }
        return newgraph;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    int n,m;
    cin>>n>>m;
    DirectedGraph g(n+1);
    rep(i,n+m-1){
        int a,b;
        cin>>a>>b;
        g.add_edge(a,b);
    }
    g.scc();
    vec v=g.vs;
    reverse(all(v));
    v.pop_back(); // 末尾削除＝＝０番目削除

    set<int> used;
    vec ans(n+1);
    for(auto now:v){
        for(auto next:g.G[now]){
            ans[next]=now;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
}