#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
int main(void) {
    double H, W, h, w;
    cin >> H >> W >> h >> w;
    cout << (H * W) - ((h * W + w * H) - (h * w))   << endl; 
    return 0;
}
