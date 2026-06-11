#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;
struct edge{int to, cost;};

template<typename T> bool chmin(T &a,const T b){if(a>b){a=b; return true;}return false;}
template<typename T> bool chmax(T &a,const T b){if(a<b){a=b; return true;}return false;}

int N, M;
vii adj;
vi color;

bool dfs(int v=0, int c=1){
    color[v]=c;
    for(auto nv : adj[v]){
        if(color[nv] == 0 && !dfs(nv, -c)) return false;
        if(color[nv] == c) return false;
    }
    return true;
}

int main(){
    cin >> N >> M;
    adj.resize(N);
    color.assign(N, 0);
    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans;
    if(dfs()){
        int c1=0, c2=0;
        for(int i=0; i<N; i++){
            if(color[i] == 1) c1++;
            else c2++;
        }
        ans=(ll)N*(N-1)/2-(ll)c1*(c1-1)/2-(ll)c2*(c2-1)/2-M;
    }
    else ans=(ll)N*(N-1)/2-M;
    cout << ans << endl;
    return 0;
}