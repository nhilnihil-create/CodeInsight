#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) for(int sz=0;sz<int(vec.size());sz++) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

using PI = P<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    V<PI> dt(n);
    for (int i = 0; i < n; i++) cin >> dt[i].second >> dt[i].first;
    sort(ALL(dt));
    reverse(ALL(dt));
    ll tmp = 0, ans = 0, tp = 0;
    V<int> tcnt(100001, 0);

    priority_queue<PI> pq;
    for (int i = 0; i < k; i++) {
        ans += ll(dt[i].first);
        tcnt[dt[i].second]++;
        if (tcnt[dt[i].second] == 1) tp++;
    }
    for (int i = 0; i < k; i++) {
        if (tcnt[dt[i].second] > 1) pq.push(PI(-dt[i].first, dt[i].second));
    }

    tmp = ans;
    ans += tp * tp;

    for (int i = k; i < n; i++) {
        if (tcnt[dt[i].second] > 0) continue;
        if (pq.empty()) {
            break;
        }
        PI q = pq.top(); pq.pop();
        while (!pq.empty() && tcnt[q.second] == 1) {
            q = pq.top(); pq.pop();
        }
        if (tcnt[q.second] == 1) break;

        tcnt[q.second]--;
        tmp += q.first;
        tmp += dt[i].first;
        tcnt[dt[i].second]++;
        tp++;
        chmax(ans, tmp + tp * tp);
    }
    cout << ans << '\n';
    return 0;
}
