#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    rep(i, h) {
        rep(j, w) {
            if (s[i][j] == '#') {
                bool flag = false;
                rep(k, 4) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny >= 0 && ny < h && nx >= 0 && nx < w && s[ny][nx] == '#')
                        flag = true;
                }
                if (!flag) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}