#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    sort(h.begin(), h.end());
    int ans = INF;
    rep(i,n) {
        if (i+k-1 >= n) break;
        ans = min(ans, h[i+k-1]-h[i]);
    }
    cout << ans << endl;
    return 0;
}