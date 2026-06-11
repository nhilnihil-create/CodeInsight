/* ---------- STL Libraries ---------- */
// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>
#include <cstring>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <stack>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
#define P pair<ll, ll>

/* ---------- Constants  */
const double PI = 3.141592653589793238462643383279;
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

struct edge {
    int to;
    int cost;
};

const int MAX_N = 100000;
bool visited[MAX_N];
int positions[MAX_N];
vector<edge> table[MAX_N];
int N, M;

bool dfs(int node, int pos) {
    positions[node] = pos;
    visited[node] = true;
    bool valid = true;

    for (edge e : table[node]) {
        if (visited[e.to]) {
            if (pos + e.cost != positions[e.to]) return false;
        } else {
            valid &= dfs(e.to, pos + e.cost);
        }
    }

    return valid;
}

signed main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int L, R, D;
        cin >> L >> R >> D;
        L--; R--;
        table[L].push_back({R, D});
        table[R].push_back({L, -D});
    }

    bool valid = true;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            valid &= dfs(i, 0);
        }
    }

    cout << (valid ? "Yes" : "No") << endl;

    return 0;
}