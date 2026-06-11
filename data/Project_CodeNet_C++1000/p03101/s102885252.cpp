#include <bits/stdc++.h>

using namespace std;

int main() {
    int H = 0, W = 0, h = 0, w = 0;
    cin >> H >> W;
    cin >> h >> w;
    cout << (H * W) - ((h * W) + (w * (H - h))) << endl;
}