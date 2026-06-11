#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n;
    cin >> n;
    int x[n], y[n], h[n];
    int l;
    rep (i, 0, n) {
        cin >> x[i] >> y[i] >> h[i];
        if (h[i] != 0) l = i;
    }
    rep (i, 0, 101) {
        rep (j, 0, 101) {
            //{i,j}を中心,高さを求めていく
            int height = h[l] + abs (x[l] - i) + abs (y[l] - j);
            bool chk = 1;
            rep (m, 0, n) {
                if (h[m] == 0) {
                    int hm = height - abs (x[m] - i) - abs (y[m] - j);
                    if (hm <= 0) continue;
                    else {
                        chk = 0;
                        break;
                    }
                }
                int H = h[m] + abs (x[m] - i) + abs (y[m] - j);
                if (height != H) {
                    chk = 0;
                    break;
                }
            }
            if (chk) {
                cout << i << " " << j << " " << height << "\n";
                return 0;
            }
        }
    }
}