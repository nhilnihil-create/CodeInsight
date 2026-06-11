#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

struct Edge {
    int to;
    int dist;
    Edge (int _t, int _d) {
        to = _t;
        dist = _d;
    }
};

int N,M;
vector < Edge > G[100010];
map < int, ll > dist;
bool flag;

void dfs (int v, ll depth)
{
    if (!flag) return;
    if (dist.find(v) != dist.end() && dist[v] != depth) {
        flag = false;
        return;
    }
    if (dist.find(v) != dist.end() && dist[v] == depth) {
        return;
    }
    dist[v] = depth;
    REP(i,G[v].size()) {
        dfs(G[v][i].to, G[v][i].dist + depth);
    }
}

int main ()
{
    cin >> N >> M;
    REP(i,M) {
        int L,R,D;
        cin >> L >> R >> D;
        G[L].push_back(Edge(R, D));
        G[R].push_back(Edge(L, -D));
    }

    flag = true;
    for (int i = 1; i <= N; i++) {
        if (dist.find(i) == dist.end()) {
            dfs(i, 0);
        } else {
            dfs(i, dist[i]);
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
