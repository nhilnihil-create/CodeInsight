#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vvl = vector<vl>;
using pl  = pair<ll,ll>;
using tl  = pair<pl,ll>;

#define ff first
#define ss second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
const ll inf = 1e9;

int main() {
    ll h, w, n;
    cin >> h >> w >> n;
    swap(h,w);
    vvl xs(h, vl(1, w));
    rep(i,n) {
        int x, y; scanf("%d %d", &x, &y);
        x--; y--;
        if (x >= y) xs[y].push_back(x);
    }
    rep(i,h) sort(all(xs[i]));

    ll ans = xs[0][0];
    ll l = 0, r = xs[0][0];
    rng(y,1,h) {
        ans = min(ans, r);
        int l_i = lower_bound(all(xs[y]), l+1) - xs[y].begin();
        int r_i = lower_bound(all(xs[y]), r-1) - xs[y].begin();

        ll curr = l;
        rng(i,l_i,r_i+1) {
            ll next = xs[y][i];
            if (next - curr > 1) {
                l = curr+1, r = next;
                break;
            }
            curr = next;
        }
    }
    cout << ans << endl;
    return 0;
}
