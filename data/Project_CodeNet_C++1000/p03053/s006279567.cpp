#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> mp(h);
    int c = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < h; i++) {
        cin >> mp[i];
        for (int k = 0; k < w; k++)
            if (mp[i][k] == '#') {
                v.push_back({i, k});
                c++;
            }
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int ans = 0;
    if (c == h*w) {
        cout << 0;
        return 0;
    }
    while (++ans) {
        vector<pair<int, int>> new_v;
        for (int i = 0; i < (int)v.size(); i++) {
            int cur_h = v[i].first;
            int cur_w = v[i].second;
            for (int i = 0; i < 4; i++) {
                int new_h = cur_h + dx[i];
                int new_w = cur_w + dy[i];
                if (new_h < 0 || h <= new_h)
                    continue;
                if (new_w < 0 || w <= new_w)
                    continue;
                if (mp[new_h][new_w] != '#') {
                    mp[new_h][new_w] = '#';
                    new_v.push_back({new_h, new_w});
                    c++;
                }
            }
        }
        v = new_v;
        if (c == h*w)
            break;
    }
    cout << ans;
    return 0;
}