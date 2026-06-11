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
    int d, g;
    cin >> d >> g;
    vector<int> p(d), c(d);
    rep(i,d) cin >> p[i] >> c[i];
    int ans = INF;
    rep(is,1<<d) {
        int sum = 0;
        int now = 0;
        int mx = -1;
        rep(i,d) {
            if (is>>i&1) {
                sum += 100*(i+1)*p[i];
                sum += c[i];
                now += p[i];
            }
            else mx = i;
        }
        if (sum < g) {
            int x = 100*(mx+1);
            sum = g - sum;
            if ((sum+x-1)/x >= p[mx]) continue;
            now += (sum+x-1)/x;
        }
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}