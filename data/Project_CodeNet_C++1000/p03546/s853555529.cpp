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
    int h, w; cin >> h >> w;
    V< V<int> > c(10, V<int>(10)), a(h, V<int>(w));
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) cin >> c[i][j];
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> a[i][j];

    for (int k = 0; k < 10; k++)
    for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++) chmin(c[i][j], c[i][k] + c[k][j]);

    int ans = 0;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
        ans += (a[i][j] == -1 ? 0 : c[a[i][j]][1]);
    }
    cout << ans << '\n';
    return 0;
}
