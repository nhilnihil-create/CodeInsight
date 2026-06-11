
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
    int n, m;
    cin >> n >> m;

    vi v[8];

    rep(i, n) {
        int x, y, z;
        cin >> x >> y >> z;

        v[0].push_back(x + y + z);
        v[1].push_back(x + y - z);
        v[2].push_back(x - y + z);
        v[3].push_back(x - y - z);
        v[4].push_back(-x + y + z);
        v[5].push_back(-x + y - z);
        v[6].push_back(-x - y + z);
        v[7].push_back(-x - y - z);
    }

    rep(i, 8) {
        sort(all(v[i]), greater());
    }

    int ans = 0;

    rep(i, 8) {
        int res = 0;
        rep(j, m) {
            res += v[i][j];
        }
        chmax(ans, res);
    }

    cout << ans;

    return 0;
}
