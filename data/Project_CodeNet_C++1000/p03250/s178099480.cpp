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
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    int ans = 0;
    rep(i,3) {
        int now = a[0]+a[1]+a[2]+a[i]*9;
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}