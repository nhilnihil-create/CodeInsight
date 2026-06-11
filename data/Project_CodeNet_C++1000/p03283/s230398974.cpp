#ifdef LOCAL
#include "libs/debug/print_list.hpp"
#define debug(x) (cout << # x ": " << x << endl)
#define dev(v, m, n) for(int i=0;i<n;++i){for(int j=0;j<m;++j){cout<<"|"<<v[j][i];}cout<<"|"<<endl;}
#else
#define debug(x) ;
#define dev(v, m, n) ;
#endif

// :----------------------------------------

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
    int n, m, q;
    cin >> n >> m >> q;

    int t[500][500] = {0};

    rep(i, m) {
        int l, r;
        cin >> l >> r;
        --l; --r;

        ++t[l][r];
    }

    int c[500][500] = {0};

    rep(i, n) {
        int res = 0;
        rep(j, n) {
            res += t[i][j];
            c[i][j] = res;
        }
    }

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        --l; --r;

        int ans = 0;
        for (int j = l; j <= r; ++j) {
            ans += c[j][r] - (l > 0 ? c[j][l - 1] : 0);
        }

        cout << ans << endl;
    }

    return 0;
}
