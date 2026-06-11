#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

struct Edge{int to,weight; Edge(int t, int w) : to(t), weight(w) {}};
using DirectedGraph = vector<vector<Edge>>;
using UndirectedGraph = vector<vector<int>>;

vector<int> color;

bool dfs(const UndirectedGraph &G,int v,int cur=0){
    color[v]=cur;
    for(auto next:G[v]){
        if(color[next] != -1){
            if(color[next]==cur) return false;
            continue;
        }
        if(!dfs(G,next,1-cur)) return false;
    }
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin>>N>>M;
    UndirectedGraph G(N);
    REP(i,M){
        int a,b;
        cin>>a>>b;
        --a,--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    color.assign(N,-1);
    bool is_bipartite=true;
    REP(v,N){
        if(color[v]!=-1) continue;
        if(!dfs(G,v)) is_bipartite = false;
    }
    if(is_bipartite){
        ll b=0,w=0;
        REP(i,N){
            if(color[i]==1) b++;
            else w++;
        }
        cout<<b*w - M<<endl;
    }
    else{
        cout<<N*(N-1)/2 - M<<endl;
    }
}
