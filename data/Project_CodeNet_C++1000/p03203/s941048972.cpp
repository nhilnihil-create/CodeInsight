#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <random>
#include <complex>
#include <random>
 
using namespace std;

const int INF = 1e9 + 239;

int h, w;

set<pair<int, int>> bans;
set<pair<int, int>> tars;

vector<set<int>> ban;
vector<set<int>> tar;

void add_tar(int x, int y) {
    tars.insert({x - y, y});
}

void add_ban(int x, int y) {
    bans.insert({x - y, y});
}

void init() {
    set<pair<int, int>> ntars;
    for (auto t : tars) {
        if (!bans.count(t)) {
            ntars.insert(t);
        }
    }
    tars = ntars;
    ban.resize(h);
    tar.resize(h);
    for (auto t : tars) {
        tar[t.first].insert(t.second);
    }
    for (auto t : bans) {
        ban[t.first].insert(t.second);
    }
    for (int i = 0; i < h; i++) {
        ban[i].insert(w);
    }
}

void print() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (tars.count({i, j})) {
                cout << 'T';
            } else if (bans.count({i, j})) {
                cout << 'B';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
}

int getl(set<int> &pb, set<int> &cb, int pl) {
    while (pb.count(pl) || cb.count(pl)) {
        pl++;
    }
    return pl;
}

int getr(set<int> &pb, set<int> &cb, int pr) {
    while (pb.count(pr) || cb.count(pr)) {
        pr--;
    }
    return pr;
}

int trimr(set<int> &cb, int pr) {
    return *cb.upper_bound(pr) - 1;
}

int solve() {
    int ans = INF;
    set<int> pb;
    int l = 0;
    int r = 0;
    for (int i = 0; i < h; i++) {
        l = getl(pb, ban[i], l);
        r = getr(pb, ban[i], r);
        r = trimr(ban[i], r);
        for (auto x : tar[i]) {
            if (l <= x && x <= r) {
                ans = min(ans, i + x);
            }
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> h >> w >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (x >= y) {
            add_ban(x, y);
        }
        if (x > y) {
            add_tar(x - 1, y);
        }
    }
    init();
    // print();
    int ans = solve();
    cout << min(h, ans + 1) << endl;
}
