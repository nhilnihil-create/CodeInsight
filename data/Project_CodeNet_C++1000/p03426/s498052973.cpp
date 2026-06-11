#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int h, w, d, px[90005], py[90005], q, l, r, sum[90005];

int main() {
    cin >> h >> w >> d;
    rep(i, h)rep(j, w) {
        int a;
        cin >> a;
        px[a] = i+1;
        py[a] = j+1;
    }
    for (int i=d+1; i<=h*w; i++) {
        sum[i] = sum[i-d] + abs(px[i] - px[i-d]) + abs(py[i] - py[i-d]);
    }
    cin >> q;
    rep(i, q) {
        cin >> l >> r;
        cout << (sum[r] - sum[l]) << endl;
    }
    return 0;
}