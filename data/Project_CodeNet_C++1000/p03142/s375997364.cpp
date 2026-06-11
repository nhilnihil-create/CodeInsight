#include <bits/stdc++.h>
#define rep(a,n) for (int a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<int,int> P;
typedef pair<ll,P> PP;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = numeric_limits<ll>::max();

/*トポロジカルソートを行う
DAGでない場合にはsize０のvectorを返す*/

struct TopologicalSort{
    int v;
    vector<vector<int> >g,g_len;
    vector<int>deg,res;//degは頂点に入ってくる辺の数
    TopologicalSort(int n) : v(n),g(v),deg(v,0),g_len(v){}
    void add_edge(int from,int to){
        g[from].push_back(to);
        g_len[to].push_back(from);
        deg[to]++;
    }
    vector<int> solve(){
        queue<int>que;
        rep(i,v){
            if(deg[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int p = que.front();
            que.pop();
            res.push_back(p);
            for(int v:g[p]){
                if(--deg[v]==0){
                    que.push(v);
                }
            }
        }
        if(*max_element(deg.begin(),deg.end())==0){
            return res;
        }
        else{
            return vector<int>();
        }
    }
    bool unique(){//解の一意性を判定する
        for(int i=0;i<v-1;i++){
            int from = res[i];
            int to = res[i+1];
            bool flg = false;
            for(int x:g[from]){
                if(x==to)flg=true;
            }
            if(!flg){
                return false;
            }
        }
        return true;
    }
    vector<int> longest_len(){//DAGである時に最長経路を求める
        vector<int>dist(v,0);
        vector<int> par(v);
        for(int i=0;i<v;i++){
            int p = -1;
            for(int x:g_len[res[i]]){
                if(chmax(dist[res[i]],dist[x]+1)){
                    p = x;
                }
            }
            par[res[i]]=p;
        }
        return par;
    }
};

int main(){
    ll n,m;
    cin >> n >> m;
    TopologicalSort tps(n);
    rep(i,n+m-1){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        tps.add_edge(a,b);
    }
    tps.solve();
    auto ans = tps.longest_len();
    rep(i,n){
        cout << ans[i]+1 << endl;
    }
    return 0;
}

