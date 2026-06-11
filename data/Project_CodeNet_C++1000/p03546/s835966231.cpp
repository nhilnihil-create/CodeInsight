#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {        
    int h, w;
    cin >> h >> w;
    vector<vector<int>> v(10, vector<int>(10, 0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> v[i][j];
        }
    }
    vector<int> dist(10, 0x3f3f3f3f);
    dist[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 1));
    while (pq.size() > 0) {
        auto p = pq.top();
        pq.pop();
        int d = -p.first;
        int index = p.second;
        if (d != dist[index]) continue;
        for (int i = 0; i < 10; i++) {
            if (i == index) continue;
            if (dist[i] > dist[index] + v[i][index]) {
                dist[i] = dist[index] + v[i][index];
                pq.push(make_pair(-dist[i], i));
            }
        }
    }
    int res = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int t;
            cin >> t;
            res += dist[t];
        }
    }
    cout << res << endl;
}
