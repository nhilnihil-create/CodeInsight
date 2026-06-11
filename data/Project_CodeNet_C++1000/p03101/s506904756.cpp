#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;

    cout << H * W - h * W - w * H + h * w << endl;

    return 0;
}
