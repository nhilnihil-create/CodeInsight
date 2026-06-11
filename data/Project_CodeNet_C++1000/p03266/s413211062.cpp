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
    ll now = (ll)(n/k)*(n/k)*(n/k);
    if (k%2 == 1) {
        ll ans = now;
        cout << ans << endl;
        return 0;
    }
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i%k == k/2) cnt++;
    }
    ll ans = cnt*cnt*cnt + now;
    cout << ans << endl;
    return 0;
}