#include <iostream>
using namespace std;
int main() {
    int H, W, h, w; cin >> H >> W >> h >> w;
    printf("%d\n", H * W - (h * W + ((H - h) * w)));
}