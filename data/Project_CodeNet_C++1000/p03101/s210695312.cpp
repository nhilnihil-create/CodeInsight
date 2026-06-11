#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll H, W, h, w;
    cin >> H >> W >> h >> w;
    cout << (H * W) - (h * W) - (w * H) + h * w << endl;
}