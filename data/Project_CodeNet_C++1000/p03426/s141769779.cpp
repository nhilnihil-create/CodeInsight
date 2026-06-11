#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;
pii operator+(pii a, pii b) { return {a.first + b.first, a.second + b.second}; }
pii operator-(pii a, pii b) { return {a.first - b.first, a.second - b.second}; }
int abs(const pii &p) { return abs(p.first) + abs(p.second); }

int main() {
    int h, w; cin >> h >> w;
    int d; cin >> d;
    vector<pii> pos(h * w);
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
        int a; cin >> a; a--;
        pos[a] = {i, j};
    }
    vector<int> dist(h * w);
    for (int i = d; i < h * w; i++) {
        dist[i] = dist[i - d] + abs(pos[i] - pos[i - d]);
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        cout << dist[r] - dist[l] << endl;
    }
    return 0;
}
