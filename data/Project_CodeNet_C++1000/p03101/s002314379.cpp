#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int H, W;
    cin >> H >> W;

    int h, w;
    cin >> h >> w;
    if (h == H || w == W)
        cout << 0;
    else
        cout << (H - h) * (W - w);
}