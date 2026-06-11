#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    rep(i, 0, h) {
        rep(j, 0, w) {
            if (s[i][j] == '#') continue;

            int cnt = 0;
            rep(k, 0, 8) {
                int ni = i + dy[k];
                int nj = j + dx[k];

                if (ni < 0 || ni >= h) continue;
                if (nj < 0 || nj >= w) continue;
                if (s[ni][nj] == '#') cnt++;
            }
            s[i][j] = char(cnt + '0');
        }
    }
    rep(i, 0, h) cout << s[i] << endl;

    return 0;
}
