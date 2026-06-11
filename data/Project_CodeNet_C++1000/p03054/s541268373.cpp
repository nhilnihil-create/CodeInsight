#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, n, sh, sw, nh, nw;
    string s, t;
    bool ans = true;
    cin >> h >> w >> n >> sh >> sw >> s >> t;
    auto reset_pos = [&]() { nh = sh; nw = sw; };
    auto is_out = [&]() { return (nh <= 0 || h < nh || nw <= 0 || w < nw);};
    
    // L のみ移動
    reset_pos();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') nw--;
        if (is_out()) ans = false;
        if (t[i] == 'R' && nw < w) nw++;
    }
    
    reset_pos();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') nw++;
        if (is_out()) ans = false;
        if (t[i] == 'L' && 1 < nw) nw--;
    }
    
    reset_pos();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') nh--;
        if (is_out()) ans = false;
        if (t[i] == 'D' && nh < h) nh++;
    }
    
    reset_pos();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') nh++;
        if (is_out()) ans = false;
        if (t[i] == 'U' && 1 < nh) nh--;
    }
    
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}