#include <bits/stdc++.h>
#define MAX_N 100000
#define INF 1000000007
using namespace std;

struct Edge {
    int to, d;
};

struct Node {
    int x, point;
};

int points[MAX_N];

bool validate(vector<Edge> es[], int n) {
    fill(points, points + n, INF);
    while (true) {
        queue<Node> que;

        int start = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (es[i].size() && points[i] == INF) {
                start = i;
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
        que.push(Node {start, 0});
        while (!que.empty()) {
            Node p = que.front();
            que.pop();
            if (points[p.x] < INF) {
                if (p.point != points[p.x])
                    return false;
            } else {
                points[p.x] = p.point;
                for (auto e: es[p.x]) {
                    que.push(Node {e.to, e.d + p.point});
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> es[n];
    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--; r--;
        es[l].push_back(Edge {r,  d});
        es[r].push_back(Edge {l, -d});
    }
    cout << ((validate(es, n)) ? "Yes" : "No") << endl;
    return 0;
}
