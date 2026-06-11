#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
#define vv(a,b,c,d) vector<vector<a> >(b,vector<a>(c,d))
#define vvv(a,b,c,d,e) vector<vector<vector<a> > >(b,vv(a,c,d,e))
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

ll f(ll A, ll B) {
    ll lim = A*B;
    ll ok = 0, ng = B;
    // x > A, y < B
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        // (A+mid, mid)
        // 1, 2, 3, 4, 5, ..., mid
        // A+mid, A+1, ..., A+1
        // A+mid+1 = x + y
        // 1<=x<=mid
        bool f = true;
        if (mid * (A + 1) >= lim)f = false;
        ll x = (A + mid + 1) / 2;
        for (ll xx = x - 2; xx < x + 3; ++xx) {
            if (xx >= 1 && xx <= mid) {
                ll y = xx * (A + 1 + mid - xx);
                if (y >= lim)f = false;
            }
        }
        (f ? ok : ng) = mid;
    }
    RT ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int Q;
    cin >> Q;
    while (Q--) {
        ll A, B;
        cin >> A >> B;

        ll bb = f(A, B);
        ll aa = f(B, A);
        ll ans = aa + bb;
        ll x = B - bb - 1, y = A - aa - 1;
        ans += max(0ll, min(x, y));
        cout << ans << endl;
    }
}