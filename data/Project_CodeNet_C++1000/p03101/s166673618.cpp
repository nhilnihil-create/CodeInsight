#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int H, W, h, w;
    cin >> H >> W >> h >> w;

    cout << (H * W - ((h * W) + (H * w) - (h * w))) << endl;

    return 0;
}
