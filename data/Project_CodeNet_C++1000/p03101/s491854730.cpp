#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int H, W, h, w;


void input() {
    cin >> H >> W >> h >> w;
}


int main() {
    input();
    int ans = (H - h) * (W - w);
    cout << ans << endl;
}
