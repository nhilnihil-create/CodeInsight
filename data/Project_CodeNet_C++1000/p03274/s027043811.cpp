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
    vector<int> mi, pr;
    rep(i,n) {
        int x;
        cin >> x;
        if (x < 0) mi.push_back(abs(x));
        else pr.push_back(x);
    }
    reverse(mi.begin(), mi.end());
    int ans = INF;
    for (int l = min(k,int(mi.size())); l >= 0; l--) {
        int r = k-l;
        if (r > pr.size()) break;
        int now = 0;
        if (l == 0) now = pr[r-1];
        else if (r == 0) now = mi[l-1];
        else {
            now = pr[r-1] + mi[l-1] + min(pr[r-1], mi[l-1]);
        }
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}