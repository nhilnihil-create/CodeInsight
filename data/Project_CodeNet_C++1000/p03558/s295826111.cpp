#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <deque>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()
#define INF 1000000000

struct edge { int to, cost; };
int K;

vector<edge> G[100000];
int d[100000];

void make_graph() {
    REP(i, K) {
        G[i].push_back({(i + 1) % K, 1});
        G[i].push_back({(i * 10) % K, 0});
    }
    fill(d, d + K, INF);
}

int main() {
    cin >> K;
    make_graph();

    deque<edge> q;
    q.push_back({1, 1});
    while (d[0] == INF) {
        int v = q.front().to, c = q.front().cost; q.pop_front();
        if (d[v] != INF) continue;
        for (edge e : G[v]) {
            if (e.cost == 0) q.push_front({e.to, c});
            else             q.push_back({e.to, c + 1});
        }
        d[v] = c;
    }
    cout << d[0] << endl;
    return 0;
}