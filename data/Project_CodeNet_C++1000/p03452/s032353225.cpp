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

constexpr int INF = INT_MAX;
constexpr int MAX_N = 100010;

struct edge {
    int to;
    int cost;
};

vector<edge> G[MAX_N];

void bfs(int v, vector<int> &costs, bool &good, int cost) {
    if (costs[v] != INF) {
        if (costs[v] != cost) good = false;
        return;
    }
    costs[v] = cost;
    for (int i = 0; i < G[v].size(); i++) {
        int to = G[v][i].to;
        bfs(to, costs, good, cost + G[v][i].cost);
    }
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

    vector<int> costs(N, INF);
    bool good = true;

    for (int i = 0; i < N; i++) {
        if (costs[i] == INF) {
            bfs(i, costs, good, 0);
        }
    }

    if(good) cout << "Yes";
    else cout << "No";

    return 0;
}















































