#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;
typedef tuple<long long, long long, long long> tllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
bool compTuple(const tllint& arg1, const tllint& arg2) { return get<2>(arg1) > get<2>(arg2); }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

vector<vector<pint>> g;
vector<vector<int>> w;
vector<int> ans;

void bfs(int s) {
    queue<pint> q;
    q.push({s, 0});

    while(!q.empty()) {
        auto uw = q.front(); q.pop();
        for(auto vw:g[uw.first]) {
            if(ans[vw.first]!=-1) continue;
            if(vw.second%2==0) ans[vw.first] = ans[uw.first];
            else ans[vw.first] = 1 - ans[uw.first];
            q.push(vw);
        }
    }
}

int main(void) {
    int n;
    cin >> n;

    g.resize(n);
    ans.resize(n, -1);

    int u, v, w;
    for(int in=0;in<n-1;++in) {
        cin >> u >> v >> w; u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    ans[0] = 0;
    bfs(0);

    for(auto ians:ans) cout << ians << endl;
    return 0;
}
