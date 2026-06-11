
#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using vi = vector<int>;
using pi = pair<int, int>;
using vp = vector<pi>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

#define P (1'000'000'007)

signed main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;

    vi va, vb, vc;
    rep(i, x) {
        capi(a);
        va.push_back(a);
    }

    rep(i, y) {
        capi(b);
        vb.push_back(b);
    }

    rep(i, z) {
        capi(c);
        vc.push_back(c);
    }

    sort(all(va), greater());
    sort(all(vb), greater());
    sort(all(vc), greater());

    vi v;

    rep(i, x) {
        rep (j, y) {
            if ((i + 1) * (j + 1) > k) break;
            rep(l, z) {
                if ((i + 1) * (j + 1) * (l + 1) > k) break;
                v.push_back(va[i] + vb[j] + vc[l]);
            }
        }
    }

    sort(all(v), greater());
    rep(i, k) {
        cout << v[i] << endl;
    }


    return 0;
}
