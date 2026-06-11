#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W; cin >> H >> W;
    int h, w; cin >> h >> w;
    cout << (H - h) * (W - w) << "\n";
}