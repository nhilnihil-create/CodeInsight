#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};



void solve(){
    ll N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    REP(i,M){
        int a, b;
        cin >> a >> b;
        G[--a].emplace_back(--b);
        G[b].emplace_back(a);
    }
    vector<int> color(N, -1);
    auto dfs = [&](auto self, int v, int cur=0) -> bool{
        color[v] = cur;
        for(auto nv:G[v]){
            if(color[nv]!=-1){
                if(color[nv]==cur) return false;
                continue;
            }
            if(!self(self, nv,1-cur)) return false;
        }
        return true;
    };
    bool bipartite = true;
    ll cnt = 0;
    REP(v,N){
        if(color[v]!=-1) continue;
        if(!dfs(dfs, v)) bipartite = false;
    }
    if(!bipartite){
        cout << N * (N - 1) / 2 - M << endl;
        return;
    }
    REP(i,N) if(color[i]) cnt++;
    cout << cnt * (N - cnt) - M << endl;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    // int T; cin >> T; REP(t,T) solve();
}