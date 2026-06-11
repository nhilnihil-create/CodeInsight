#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;
typedef pair<int,int> P;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k,q;
    cin >> n >> k >> q;
    vector<int> a(n),b(n);
    REP(i,n) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(),b.end());

    int ans = inf;
    REP(i,n) {
        vector<int> v, vv;
        REP(j,n) {
            if (a[j] < b[i]) {
                if (sz(vv) >= k) {
                    sort(vv.begin(), vv.end());
                    REP(kk, sz(vv) - k + 1) {
                        v.pb(vv[kk]);
                    }
                }
                vv.clear();
            } else {
                vv.pb(a[j]);
            }
        }
        if (sz(vv) >= k) {
            sort(vv.begin(), vv.end());
            REP(kk, sz(vv) - k + 1) {
                v.pb(vv[kk]);
            }
        }

        if (sz(v) < q) break;
        sort(v.begin(), v.end());
        ans = min(ans, v[q-1] - v[0]);

    }

    cout << ans << endl;
    return 0;
}
