#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<tuple>
#include<sstream>
#include<functional>
#include<list>
#include<queue>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> p;
typedef vector<int> vec;
using Graph = vector<vector<int>>;
using graph = vector<vector<ll>>;

const long long INF = 1LL << 60;
const ll inf = 1e9;
const long long MOD = 1000000007;

const int MAX_V = 1000000;

//辺を表す構造体（行先、容量、逆辺）
struct edge { int to, cap, rev; };

vector<vector<edge>> G(MAX_V);        //グラフの隣接リスト表現
int level[MAX_V];                     //ｓからの距離
int iter[MAX_V];                      //どこまで調べ終わったか

//fromからtoへ向かう容量capの辺をグラフに張る
void add_edge(int from, int to, int cap) {
    edge F, T;
    F.to = to; F.cap = cap; F.rev = G[to].size();
    G[from].push_back(F);

    T.to = from; T.cap = 0; T.rev = G[from].size() - 1;
    G[to].push_back(T);
}

//sからの最短経路をBFSで調べる
void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        rep(i, G[v].size()) {
            edge& e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

//増加パスをdfsで調べる
int dfs(int v, int t, int f) {
    if (v == t)return f;
    for (int& i = iter[v]; i < G[v].size(); i++) {
        edge& e = G[v][i];                  //辺の容量を更新するのでアドレスをもっておく
        if (level[v] < level[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;                 //使った分容量を減らす
                G[e.to][e.rev].cap += d;    //使った分逆辺の容量を増やす
                return d;
            }
        }
    }
    return 0;
}

//sからｔへの最大流を求める
int max_flow(int s, int t) {
    int flow = 0;
    for (;;) {
        bfs(s);
        if (level[t] < 0)return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, inf)) > 0) {
            flow += f;
        }
    }
}


int main() {
    int n;
    cin >> n;
    vector<P> v1(n), v2(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        v1[i] = P(a, b);
    }
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        v2[i] = P(a, b);
    }
    rep(i, n) {
        rep(j, n) {
            if (v1[i].first < v2[j].first && v1[i].second < v2[j].second) {
                add_edge(i, j+n, 1);
            }
        }
    }
    rep(i, n) {
        add_edge(n * 2, i, 1);
        add_edge(n + i, n * 2 + 1, 1);
    }
    cout << max_flow(n * 2, n * 2 + 1) << endl;
    return 0;
}