#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int H, W, h, w;
int main() {
    cin >> H >> W >> h >> w;
    cout << (H - h) * (W - w) << endl;
    return 0;
}
