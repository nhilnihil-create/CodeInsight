#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    string ans = "Yes";
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '.') continue;
            bool t = false;
            rep(d, 4) {
                int nx = j + dx[d];
                int ny = i + dy[d];
                if(nx < 0 || nx >= w) continue;
                if(ny < 0 || ny >= h) continue;
                if(s[ny][nx] == '#') t = true;
            }
            if(t == false) ans = "No";
        }
    }
    cout << ans << endl;
    return 0;
}
