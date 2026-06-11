#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int H, W;
    cin >> H >> W;
    int h, w;
    cin >> h >> w;
    cout << H * W - h* W - w * H + h * w << endl;
}
