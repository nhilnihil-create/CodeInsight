#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

struct Edge{
    // 始点, 終点, 重み, 最大量
    long long src, dst, weight, capacity;
    Edge(): src(0), dst(0), weight(0), capacity(0) {}
    Edge(long long s, long long d, long long w): src(s), dst(d), weight(w) {}
    Edge(long long s, long long d, long long w, long long c): src(s), dst(d), weight(w), capacity(c) {}
};

class Graph{
public:
    long long size;
    vector<vector<Edge>> node;
    Graph(long long n): size(n), node(n) {}
    void addEdge(long long s, long long d, long long w = 1){
        node[s].emplace_back(s, d, w);
        node[d].emplace_back(d, s, w);
    }
};

int main(){
    Init();
    /* ----------入力---------- */
    ll n; cin >> n;
    Graph g(n);
    rep(i, n-1){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g.addEdge(a, b);
    }
    vi c(n);
    rep(i, n) cin >> c[i];

    /* ----------ノード0を根として、bfsで降順にciを割り当てていく---------- */
    sort(all(c), greater<ll>());
    ll sum = 0, pos = 0;
    vi ans(n), chk(n, 0);
    queue<ll> que;
    que.push(0);
    chk[0] = 1;
    while(que.size()){
        auto f = que.front();
        que.pop();
        ans[f] = c[pos];
        if(f) sum += ans[f];
        pos++;
        for(auto &edge: g.node[f]){
            if(chk[edge.dst]) continue;
            else{
                chk[edge.dst] = 1;
                que.push(edge.dst);
            }
        }
    }
    cout << sum << endl;
    for(ll i=0; i<n; i++) cout << ans[i] << (i == n-1 ? endl : " ");
}