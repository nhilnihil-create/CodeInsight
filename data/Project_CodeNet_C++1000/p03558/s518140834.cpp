#include <queue>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int dist[n];
    fill(dist, dist+n, 100);
    priority_queue<pair<int, int> > pq;
    for (int i = 1; i < min(10, n); i++)
        if (dist[i] > i) {
            dist[i] = i;
            pq.push({-i, i});
        }
    while (!pq.empty()) {
        int d = -pq.top().first, r = pq.top().second;
        pq.pop();
        if (dist[r] < d) continue;
        for (int i = 0; i < 10; i++) {
            int r1 = (r * 10 + i) % n, d1 = d + i;
            if (dist[r1] > d1) {
                dist[r1] = d1;
                pq.push({-d1, r1});
            }
        }
    }
    cout << dist[0] << endl;
}
