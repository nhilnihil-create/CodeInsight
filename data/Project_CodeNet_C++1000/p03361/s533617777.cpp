#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < n; ++i)
#define rrep(i, n) for (int i = n - 1; i > -1; --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
const long long INF = 1000000000;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    rep(i, 0, h) {
        rep(j, 0, w) { cin >> s[i][j]; }
    }
    bool f = false;
    rep(i, 0, h) {
        rep(j, 0, w) {
            if (s[i][j] == '.') continue;
            f = false;
            if (i != 0 && s[i - 1][j] == '#') f = true;
            if (i != h - 1 && s[i + 1][j] == '#') f = true;
            if (j != 0 && s[i][j - 1] == '#') f = true;
            if (j != w - 1 && s[i][j + 1] == '#') f = true;
            if (!f) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}