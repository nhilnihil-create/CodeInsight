#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '#') continue;
            else {
                int cnt = 0;
                rep(d, 8) {
                    int nx = j;
                    int ny = i;
                    nx += dx[d];
                    ny += dy[d];
                    if(nx < 0 || nx >= w) continue;
                    if(ny < 0 || ny >= h) continue;
                    if(s[ny][nx] == '#') cnt++;
                }
                s[i][j] = (char) (cnt + '0');
            }
        }
    }
    rep(i, h) {
        cout << s[i] << endl;
    }
    return 0;
}
