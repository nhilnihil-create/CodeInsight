#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int K = 100000 + 5;

int k;
vector<PII> g[K];
queue<int> q;
int d[K], inq[K];

int main() {
    scanf("%d", &k);
    for (int i = 1; i < k; ++i) {
        g[i].push_back(make_pair((i + 1) % k, 1));
        g[i].push_back(make_pair((i * 10) % k, 0));
    }
    memset(d, 0x3f, sizeof(d));
    d[1] = 0, q.push(1), inq[1] = 1;
    while (q.size()) {
        int x = q.front(); q.pop(); inq[x] = 0;
        for (int i = 0; i < g[x].size(); ++i) {
            int y = g[x][i].first;
            if (d[x] + g[x][i].second < d[y]) {
                d[y] = d[x] + g[x][i].second;
                if (!inq[y]) q.push(y), inq[y] = 1;
            }
        }
    }
    printf("%d\n", d[0] + 1);
    return 0;
}
