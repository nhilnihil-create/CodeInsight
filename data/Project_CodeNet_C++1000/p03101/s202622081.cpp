#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W, h, w;
    cin >> H >> W;
    cin >> h >> w;

    int ans = (H - h) * (W - w);

    cout << ans << endl;
}