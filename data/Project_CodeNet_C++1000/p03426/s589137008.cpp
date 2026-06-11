#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int h, w, d, px[90005], py[90005], q, l[100005], r[100005], sum[90005];

int main() {
    cin >> h >> w >> d;
    rep(i, h)rep(j, w) {
        int a;
        cin >> a;
        px[a] = i;
        py[a] = j;
    }
    for (int i=d+1; i<=h*w; i++) {
        sum[i] = sum[i-d] + abs(px[i] - px[i-d]) + abs(py[i] - py[i-d]);
    }
    cin >> q;
    rep(i, q) cin >> l[i] >> r[i];
    rep(i, q) {
        cout << (sum[r[i]] - sum[l[i]]) << endl;
    }
    return 0;
}