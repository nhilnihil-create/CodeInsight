#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

vector<vector<pii>>graph;
int n;
vector<int> res;
// v: 頂点、p: 親、pc: vを塗る色、
void dfs(int v, int p, int pc){
    res[v] = pc;
    for(auto i:graph[v]){
        // (隣接頂点, 辺番号)
        if(i.first==p)continue;
        if(i.second%2==1)dfs(i.first, v, 1-pc);
        else dfs(i.first, v, pc);
    }
}
int main(){
    cin >> n;
    graph.assign(n, vector<pii>());
    res.assign(n, 0);
    rep(i, 0, n-1){
        int p, q, r;
        cin >> p >> q >> r;
        p--,q--;
        graph[p].push_back({q, r});
        graph[q].push_back({p, r});
    }
    int ans2=-1;
    dfs(0, -1, 0);
    for(auto i:res){
        cout << i << endl;
    }
}