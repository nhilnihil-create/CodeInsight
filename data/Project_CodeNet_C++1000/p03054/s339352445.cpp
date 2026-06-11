#include <bits/stdc++.h>

using namespace std;

int max_subsequence(vector<int> xs) {
    int hi = 0;
    int current_lo = 0;
    int current_sum = 0;
    for (auto x : xs) {
        current_sum += x;
        current_lo = min(current_lo, current_sum);
        hi = max(hi, current_sum - current_lo);
    }
    return hi;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, n;
    int s_r, s_c;
    string s, t;
    cin >> h >> w >> n;
    cin >> s_r >> s_c;
    cin >> s >> t;
    auto f = [&](int start, char x, char y) {
        vector<int> xs;
        xs.push_back(start);
        for (int i = 0; i < n; ++i) {
            if (s[i] == x) {
                xs.push_back(1);
            }
            if (t[i] == y) {
                xs.push_back(-1);
            }
        }
        return xs;
    };
    bool a = max_subsequence(f(s_c - 1, 'R', 'L')) >= w;
    bool b = max_subsequence(f(w - s_c, 'L', 'R')) >= w;
    bool c = max_subsequence(f(s_r - 1, 'D', 'U')) >= h;
    bool d = max_subsequence(f(h - s_r, 'U', 'D')) >= h;
    if (a || b || c || d) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}
