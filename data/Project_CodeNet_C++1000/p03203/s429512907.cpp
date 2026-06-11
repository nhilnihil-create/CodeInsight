#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w; cin >> h >> w;
    int n; cin >> n;
    vector<vector<int>> obs(h);
    while (n--) {
        int i, j; cin >> i >> j, i--, j--;
        obs[i].emplace_back(j);
    }
    int mi = h, cnt = 0;
    for (int i = 0; i < h; i++) {
        sort(begin(obs[i]), end(obs[i]));
        for (int j: obs[i]) {
            if (i - cnt == j) cnt++;
            if (i - cnt > j) mi = min(mi, i);
        }
    }
    cout << mi << endl;
    return 0;
}
