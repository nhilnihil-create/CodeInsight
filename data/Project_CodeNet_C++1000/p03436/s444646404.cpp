#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> mp(h);
    int initial_count = 0;
    for (int i = 0; i < h; i++) {
        cin >> mp[i];
        for (int k = 0; k < w; k++)
            if (mp[i][k] == '#')
                initial_count++;
    }
    queue<tuple<int, int, int>> q;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    q.push({0, 0, 0});
    mp[0][0] = '-';
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int cur_h = get<0>(front);
        int cur_w = get<1>(front);
        int cur_count = get<2>(front);
        if (cur_h == h-1 && cur_w == w-1) {
            cout << h*w - initial_count - cur_count - 1;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int new_h = cur_h + dx[i];
            int new_w = cur_w + dy[i];
            if (new_h < 0 || new_h >= h)
                continue;
            if (new_w < 0 || new_w >= w)
                continue;
            if (mp[new_h][new_w] == '.') {
                mp[new_h][new_w] = '-';
                q.push({new_h, new_w, cur_count+1});
            }
        }
    }
    cout << -1;
    return 0;
}