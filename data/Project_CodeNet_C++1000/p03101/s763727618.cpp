#include <bits/stdc++.h>
using namespace std;

signed main() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    
    cout << (H*W) - (w*H) - (h*W) + (h*w) << endl;
    return (0);
}