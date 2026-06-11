#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<string>> mat(H);
    queue<vector<P>> q;
    vector<P> p;
    // cout << "B" << endl;
    // cout << "mat: " << mat.size() << endl;

    rep(i, H) {
        string t;
        cin >> t;
        // cout << "?" << endl;

        rep(j, W) {
            string tt = {t[j]};
            // cout << "tt: " << tt << endl;

            mat[i].pb(tt);
            if (tt == "#") {
                p.pb({i, j});
            }
        }
    }
    // cout << "C" << endl;

    q.push(p);
    // cout << "D" << endl;

    int count = 0;
    while (!q.empty()) {
        vector<P> pp = q.front();
        // cout << "q.size(): " << q.size() << endl;
        q.pop();
        vector<P> tmp;
        for (P p : pp) {
            // cout << "x: " << p.first << " y: " << p.second << endl;
            // cout << "1" << endl;
            if (p.first > 0 && mat[p.first - 1][p.second] == ".") {
                mat[p.first - 1][p.second] = "#";
                tmp.pb({p.first - 1, p.second});
            }
            // cout << "2" << endl;
            // cout << "21" << endl;
            // cout << "p.first: " << p.first << endl;
            // cout << "W: " << W << endl;
            // cout << "mat.size(): " << mat.size() << endl;

            if (p.first < H - 1 && mat[p.first + 1][p.second] == ".") {
                // cout << "22" << endl;

                mat[p.first + 1][p.second] = "#";
                tmp.pb({p.first + 1, p.second});
            }
            // cout << "3" << endl;

            if (p.second > 0 && mat[p.first][p.second - 1] == ".") {
                mat[p.first][p.second - 1] = "#";
                tmp.pb({p.first, p.second - 1});
            }
            // cout << "4" << endl;

            if (p.second < W - 1 && mat[p.first][p.second + 1] == ".") {
                mat[p.first][p.second + 1] = "#";
                tmp.pb({p.first, p.second + 1});
            }
        }
        if (!tmp.empty()) {
            q.push(tmp);
        }
        // cout << "count++" << endl;

        count++;
    }

    cout << count - 1 << endl;
    return 0;
}