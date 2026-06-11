#include <iostream>
using namespace std;

int main() {
    int H, W;
    int h, w;
    cin >> H >> W;
    cin >> h >> w;

    if (H <= h || W <= w) cout << 0 << endl;
    else cout << (H - h) * (W - w) << endl;
}