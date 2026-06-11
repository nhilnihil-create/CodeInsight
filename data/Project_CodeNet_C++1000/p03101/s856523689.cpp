#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main() {
    int H, W;
    int h, w;
    cin >> H >> W;
    cin >> h >> w;
    cout << (H-h)*(W-w) << endl;
}