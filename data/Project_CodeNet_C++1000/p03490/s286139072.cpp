#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    string s;
    int x, y;
    cin >> s >> x >> y;
    int sl = s.length();
    int fcnt = 0, tcnt = 0, ftmp = 0;
    vector<int> f;
    set<pair<int, int>> pos;
    set<int> xpos, ypos;
    bool xfind = false, yfind = false, ans = false;
    rep(i, sl) {
        if (s[i] == 'F') {
            fcnt++;
            ftmp++;
            if (i == (sl - 1)) f.push_back(ftmp);
        }
        else if (s[i] == 'T') {
            tcnt++;
            f.push_back(ftmp);
            ftmp = 0;
        }
    }
    if (sz(f) == 1) {
        if ((x == f[0]) && (y == 0)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    rep(i, (sz(f) + 1) / 2) {
        if (xpos.empty()) {
            xpos.emplace(f[i * 2]);
            continue;
        }
        set<int> add;
        for(auto p : xpos) {
            add.emplace(p + f[i * 2]);
            add.emplace(p - f[i * 2]);
        }
        xpos.clear();
        for(auto p : add) xpos.emplace(p);
    }
    rep(i, sz(f) / 2) {
        if (ypos.empty()) {
            ypos.emplace(f[i * 2 + 1]);
            ypos.emplace(-1 * f[i * 2 + 1]);
            continue;
        }
        set<int> add;
        for(auto p : ypos) {
            add.emplace(p + f[i * 2 + 1]);
            add.emplace(p - f[i * 2 + 1]);
        }
        ypos.clear();
        for(auto p : add) ypos.emplace(p);
    }
    for (auto p : xpos) {
        if (p == x) xfind = true;
    }
    for (auto p : ypos) {
        if (p == y) yfind = true;
    }
    ans = (xfind && yfind);
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
