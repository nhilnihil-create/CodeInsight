#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, N; cin >> H >> W >> N;
    int sx, sy; cin >> sx >> sy;
    string s,t; cin >> s >> t;
    
    // L
    int x = sy;
    for(int i=0; i<N; ++i) {
        if(s[i] == 'L') --x;
        if(x < 1) {
            cout << "NO" << endl; return 0;
        }
        if(t[i] == 'R' && x < W) ++x;
    }

    // R
    x = sy;
    for(int i=0; i<N; ++i) {
        if(s[i] == 'R') ++x;
        if(x > W) {
            cout << "NO" << endl; return 0;
        }
        if(t[i] == 'L' && x > 1) --x;
    }

    // U
    int y = sx;
    for(int i=0; i<N; ++i) {
        if(s[i] == 'U') --y;
        if(y < 1) {
            cout << "NO" << endl; return 0;
        }
        if(t[i] == 'D' && y < H) ++y;
    }

    // D
    y = sx;
    for(int i=0; i<N; ++i) {
        if(s[i] == 'D') ++y;
        if(y > H) {
            cout << "NO" << endl; return 0;
        }
        if(t[i] == 'U' && y > 1) --y;
    }

    cout << "YES" << endl;
}