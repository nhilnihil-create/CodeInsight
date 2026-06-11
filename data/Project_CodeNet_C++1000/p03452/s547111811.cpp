//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <random>
#include <complex>
#include <regex>

using namespace std;

#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v){std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}

constexpr int MAX_N = 100010;

struct edge {
    int to;
    int cost;
};

vector<edge> G[MAX_N];
constexpr int INF = INT_MAX;

void bfs(int v, vector<int> &dp, bool &good, int cost) {
    if (dp[v] != INF) {
        if (dp[v] != cost) good = false;
        return;
    }
    dp[v] = cost;
    for (int i = 0; i < G[v].size(); i++) bfs(G[v][i].to, dp, good, cost + G[v][i].cost);
}

int main() {

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--, r--;
        G[l].push_back({r, d});
        G[r].push_back({l, -d});
    }

    vector<int> dp(N, INF);
    bool good = true;
    for (int i = 0; i < N; i++) if (dp[i] == INF)bfs(i, dp, good, 0);

    cout << (good ? "Yes" : "No") << endl;

}











































