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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> l(n), r(n);
    rep(i,n-1) {
        l[i+1] = __gcd(l[i], a[i]);
    }
    rep(i,n-1) {
        r[i+1] = __gcd(r[i], a[n-1-i]);
    }
    int ans = 0;
    rep(i,n) {
        int now = __gcd(l[i],r[n-1-i]);
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}