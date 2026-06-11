#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> G(10, vector<int>(10));
    int c;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c;
            G[j][i] = c;
        }
    }
    vector<int> dist(10, 10001);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(make_pair(0, 1));
    while (!Q.empty()) {
        for (int i = 0; i < 10; i++) {
            if (dist[i] > Q.top().first + G[Q.top().second][i]) {
                dist[i] = Q.top().first + G[Q.top().second][i];
                Q.push(make_pair(dist[i], i));
            }
        }
        Q.pop();
    }
    int sum = 0, A;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A;
            if (A == -1) continue;
            sum += dist[A];
        }
    }
    cout << sum << endl;
}
