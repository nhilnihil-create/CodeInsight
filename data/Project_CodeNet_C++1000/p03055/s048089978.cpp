#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

graph g;
int N;
vector<int> d;

void dfs(int a,int s){
    d[s] = 0;
    for(auto x:g[a]){
        if(d[x]!=-1) continue;
        d[x] = d[a] + 1;
        dfs(x,s);
    }
    return;
}

int main() {
    cin>>N;
    g.resize(N);
    d.assign(N,-1);
    rep(i,N-1) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,0);
    int l = 0;
    int u = 0,v = 0;
    rep(i,N){
        if(chmax(l,d[i])) u = i;
    }
    rep(i,N) d[i] = -1;
    dfs(u,u);
    int L = 0;
    rep(i,N) chmax(L,d[i]);
    if(L%3==1) cout<<"Second"<<endl;
    else cout<<"First"<<endl;
}