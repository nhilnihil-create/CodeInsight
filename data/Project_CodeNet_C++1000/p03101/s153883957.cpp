#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    int ans = H * W;

    ans -= h * W;
    ans -= w * H;
    ans += h * w;

    cout << ans << "\n";
}