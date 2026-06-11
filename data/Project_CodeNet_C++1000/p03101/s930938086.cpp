#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int H,W;
    cin >> H >> W;
    int h,w;
    cin >> h >> w;
    int ans = 0;
    ans += H * W;
    ans -= h * W;
    ans -= w * (H - h);

    cout << ans;

    return 0;
}