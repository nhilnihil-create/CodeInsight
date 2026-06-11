#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int H, W, h, w;
    cin >> H >> W >> h >> w;

    cout << (H * W) - (h * W + w * H - h * w);

    return 0;
}
