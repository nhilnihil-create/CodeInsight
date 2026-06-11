#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(std::unique(all(x)), x.end());
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=acos(-1);
using namespace std;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
template<class T>bool chmax(T &a, const T &b) { if (a<=b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<=a) { a=b; return 1; } return 0; }
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

vector<vector<int>> graph;
void dfs(int now,int parent,vector<int> &d) {
    if(parent!=-1) d[now]=d[parent]+1;
    for(int child:graph[now]) {
        if(child==parent) continue;
        dfs(child,now,d);
    }
}

int main() {
    int n;
    cin>>n;
    graph.resize(n);
    rep(i,n-1) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int> d1(n);
    dfs(0,-1,d1);
    int MAX=-1,t;
    rep(i,n) {
        if(chmax(MAX,d1[i])) t=i;
    }
    
    vector<int> d2(n);
    dfs(t,-1,d2);
    int r=0;
    rep(i,n) chmax(r,d2[i]);
    r++;
    
    vector<bool> dp(r+10);
    dp[0]=false;
    dp[1]=true;
    dp[2]=false;
    FOR(i,3,r) {
        if(!dp[i-1] || !dp[i-2]) dp[i]=true;
    }
    cout<<(dp[r] ? "First" : "Second")<<endl;
    
}
