#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int H, W, h, w;
    cin >> H >> W >> h >> w;

    int masu = H * W;
    cout << masu - h * W - ((w * H) - (w * h)) << endl;

    return 0;
}