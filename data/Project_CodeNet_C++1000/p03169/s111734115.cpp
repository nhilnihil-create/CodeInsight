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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int n; cin >> n;
    int c1 = 0, c2 = 0, c3 = 0;
    V<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) c1++;
        if (a[i] == 2) c2++;
        if (a[i] == 3) c3++;
    }

    V< V< V<double> > > dp(c1 + c2 + c3 + 1, V< V<double> >(c2 + c3 + 1, V<double>(c3 + 1, -1)));
    auto memo = [&](auto && self, int r1, int r2, int r3) -> double {
        if (r1 == 0 && r2 == 0 && r3 == 0) return dp[r1][r2][r3] = 0;
        if (dp[r1][r2][r3] >= 0) return dp[r1][r2][r3];

        double sum = n;
        if (r1 > 0) sum += double(r1) * self(self, r1 - 1, r2, r3);
        if (r2 > 0) sum += double(r2) * self(self, r1 + 1, r2 - 1, r3);
        if (r3 > 0) sum += double(r3) * self(self, r1, r2 + 1, r3 - 1);
        return dp[r1][r2][r3] = sum / double(r1 + r2 + r3);
    };
    cout << memo(memo, c1, c2, c3) << '\n';
    return 0;
}
