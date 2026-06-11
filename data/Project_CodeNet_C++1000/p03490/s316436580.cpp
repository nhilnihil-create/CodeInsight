#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int sx = 0, sy = 0, gx, gy;
    cin >> gx >> gy;
    int i = 0;
    while (i < s.length() && s[i] == 'F') {
        sx++;
        i++;
    }
    i++;
    vector<int> vx, vy;
    bool direc_x = false;
    int F_cnt = 0;
    for (i; i < s.length(); ++i) {
        if (s[i] == 'F' && i != s.length() - 1) F_cnt++;
        else {
            if (s[i] == 'F') F_cnt++; //最後のF
            if (direc_x) vx.push_back(F_cnt);
            else vy.push_back(F_cnt);
            direc_x ^= 1;
            F_cnt = 0;
        }
    }
    set<int> st_x, st_y;
    st_x.insert(sx);
    st_y.insert(sy);
    for (auto move : vx) {
        set<int> before_pos = st_x;
        st_x.clear();
        for (auto b : before_pos) {
            st_x.insert(b + move);
            st_x.insert(b - move);
        }
    }
    for (auto move : vy) {
        set<int> before_pos = st_y;
        st_y.clear();
        for (auto b : before_pos) {
            st_y.insert(b + move);
            st_y.insert(b - move);
        }
    }
    cout << (st_x.count(gx) && st_y.count(gy) ? "Yes" : "No") << endl;
    return 0;
}
