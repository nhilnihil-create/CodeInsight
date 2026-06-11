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
    ll ans = 0;
    int r = 0;
    ll sum = 0;
    for (int l = 0; l < n; l++) {
        while (r < n) {
            if ((sum^a[r]) != (sum+a[r])) break;
            sum += a[r];
            r++;
        }
        ans += r-l;
        sum -= a[l];
    }
    cout << ans << endl;
    return 0;
}