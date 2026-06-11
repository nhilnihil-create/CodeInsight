/**
*    author:  Taichicchi
*    created: 10.09.2020 20:20:25
**/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {

    int H, W, h, w;

    cin >> H >> W;
    cin >> h >> w;

    int ans;

    ans = H * W - (h * W + (H - h) * w);
    cout << ans << endl;

    return 0;
}