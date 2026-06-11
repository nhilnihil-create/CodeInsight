#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
queue<pair<int, int> > q;
int main () {
    int h, w;
    cin >> h >> w;
    bool white[h + 1][w + 1];
    int count[h + 1][w + 1];
    memset(count, -1, sizeof(count));
    for (int i = 1; i <= h; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= w; j++) {
            if (s[j - 1] == '.') {
                white[i][j] = true;
            }
            else {
                white[i][j] = false;
                q.push(make_pair(i, j));
                count[i][j] = 0;
            }
        }
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (q.size()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextx = p.first + dx[i];
            int nexty = p.second + dy[i];
            if ((1 <= nextx) && (nextx <= h) && (1 <= nexty) && (nexty <= w) && (count[nextx][nexty] == -1) && (white[nextx][nexty])) {
                count[nextx][nexty] = count[p.first][p.second] + 1;
                q.push(make_pair(nextx, nexty));
            }
        }
    }
    int max = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (count[i][j] > max) {
                max = count[i][j];
            }
        }
    }
    cout << max << endl;
    return 0;
}