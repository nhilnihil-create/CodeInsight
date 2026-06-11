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
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    int d = min(n,k);
    int ans = 0;
    for (int i = 0; i <= d; i++) {
        for (int l = 0; l <= i; l++) {
            int r = i-l;
            vector<int> c;
            int tot = 0;
            for (int j = 0; j <= l-1; j++) {
                c.push_back(v[j]);
                tot += v[j];
            }
            for (int j = n-r; j <= n-1; j++) {
                c.push_back(v[j]);
                tot += v[j];
            }
            sort(c.begin(), c.end());
            int ta = k-i;
            rep(j,ta) {
                if (j >= c.size()) break;
                if (c[j] >= 0) break;
                tot -= c[j];
            }
            ans = max(ans, tot);
        }
    }
    cout << ans << endl;
    return 0;
}