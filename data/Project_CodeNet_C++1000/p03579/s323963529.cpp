/*
　　　  ∧＿∧　やあ
　　 （´・ω・｀)　　　　　/　　　　　ようこそ、バーボンハウスへ。
　　 ／∇y:::::＼　　　 [￣]　　　　　このテキーラはサービスだから、まず飲んで落ち着いて欲しい。
　　 |:⊃:|:::::|　　　|──|
￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|　うん、「また」なんだ。済まない。
￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|￣　  仏の顔もって言うしね、謝って許してもらおうとも思っていない。
￣￣￣￣￣￣￣￣￣￣￣￣￣￣／|
　　　　∇　∇　∇　∇　　　／.／|　　　でも、この提出を見たとき、君は、きっと言葉では言い表せない
　　　　┴　┴　┴　┴　／ ／　  |　　　「ときめき」みたいなものを感じてくれたと思う。
￣￣￣￣￣￣￣￣￣￣|／　　  |　　　殺伐としたコンテストの中で、そういう気持ちを忘れないで欲しい
￣￣￣￣￣￣￣￣￣￣　　　　 |　　　そう思って、この提出を投げたんだ。
　　　(⊆⊇)　(⊆⊇)　(⊆⊇)　　|
　    ||　　 ||　　||　　|　　　 じゃあ、判定を聞こうか。
　　.／|＼　／|＼ ／|＼
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define fst first
#define snd second
#define ALL(obj) (obj).begin(),(obj).end()
#define debug(x) cerr << #x << " -> " << x << " (line:" << __LINE__ << ")" << '\n';
#define debugpair(x, y) cerr << "(" << #x << ", " << #y << ") -> (" << x << ", " << y << ") (line:" << __LINE__ << ")" << '\n';
typedef long long lint;
typedef priority_queue<int> p_que;
typedef priority_queue<int, vector<int>, greater<int>()> p_que_rev;
// const int INF = INT_MAX;
const lint LINF = LLONG_MAX;
const int MOD = 1000000000 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int di[]{0, -1, 0, 1, -1, -1, 1, 1};
const int dj[]{1, 0, -1, 0, 1, -1, -1, 1};

// Graph Templates
using Weight = lint;
// using Flow = int;
struct Edge {
    int src, dst;
    Weight weight;
    // Flow cap;
    Edge() : src(0), dst(0), weight(0) {}
    Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;
const Weight INF = numeric_limits<Weight>::max() / 8;

// add edge a <--(weight = w)--> b
void add_edge(Graph &g, int a, int b, Weight w) {
    g[a].push_back(Edge(a, b, w));
    g[b].push_back(Edge(b, a, w));
}

// add edge a --(weight = w)--> b
void add_arc(Graph &g, int a, int b, Weight w) { g[a].push_back(Edge(a, b, w)); }

lint color1 = 0;
lint color2 = 0;

bool checkBipartite(Graph &g, lint n){
    vector<int> color(n, -1);
    queue<pair<int, int>> que;
    // snd -> 0 or 1
    que.push(make_pair(0, 0));
    bool ret = true;
    while(!que.empty() && ret){
        auto p = que.front();
        int node = p.fst;
        int node_color = p.snd;
        color[node] = node_color;
        //debugpair(node, node_color);
        que.pop();
        for (int i=0; i<(int)g[node].size(); ++i){
            auto next = g[node][i].dst;
            if(color[next] == -1){
                que.push(make_pair(next, (node_color + 1) % 2));
            }
            else if(color[next] == 0 && node_color == 0){
                ret = false;
                break;
            }
            else if(color[next] == 1 && node_color == 1){
                ret = false;
                break;
            }
        }
    }
    if(ret){
        for (int i=0; i<n; ++i){
            //debug(color[i]);
            if(color[i] == 0){
                color1++;
            }
            else {
                color2++;
            }
        }
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    lint n, m;
    cin >> n >> m;
    Graph g(n);
    int a, b;
    lint ans;
    for (int i=0; i<m; ++i){
        cin >> a >> b;
        a--;
        b--;
        add_edge(g, a, b, 1);
    }
    bool isBipartite = checkBipartite(g, n);
    if(isBipartite){
        ans = color1 * color2 - m;
    }
    else {
        ans = (n * (n - 1)) / 2 - m;
    }
    cout << ans << endl;
    return 0;
}