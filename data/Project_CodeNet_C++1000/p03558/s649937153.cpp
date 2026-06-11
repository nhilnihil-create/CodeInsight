#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int K;
priority_queue<pii> pq;
int dist[100010];

int main() {
    scanf("%d", &K);

    for(int i = 0; i < 100010; i++) dist[i] = 1e9;
    for(int i = 1; i < min(K, 10); i++) {
        pq.push({-i, i});
        dist[i] = i;
    }

    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[u]) continue;

        for(int i = 0; i < 10; i++) {
            int v = (10 * u + i) % K;
            int w = i;

            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ -dist[v], v });
            }
        }
    }

    printf("%d", dist[0]);
}
