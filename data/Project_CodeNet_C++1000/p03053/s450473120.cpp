#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int di[] = {-1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> m(h);
    for (int i = 0; i < h; i++) {
        cin >> m[i];
    }

    queue<P> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == '#') {
                q.emplace(i, j);
            }
        }
    }
    q.emplace(-1, -1);

    int ans = 0;
    while (true) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (i == -1 && j == -1) {
            if (q.empty()) {
                break;
            }
            ans++;
            q.emplace(-1, -1);
            continue;
        }
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
                if (m[ni][nj] == '.') {
                    m[ni][nj] = '#';
                    q.emplace(ni, nj);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
