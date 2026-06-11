#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <string>
#include <utility>
#include <map>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <stack>
#include <tuple>

using namespace std;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
const int INF = 100000000;
const long long LINF = 1000000000000000000;
const long long MOD = 998244353;
const double EPS = 1e-6;
using pii = std::pair<int, int>;
using ll = long long;
using pLL = std::pair<ll, ll>;
#define SORT(v) std::sort(v.begin(), v.end())
#define RSORT(v) std::sort(v.rbegin(), v.rend())
constexpr auto PI = 3.14159265358979323846264338327950L;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int D, G;
    cin >> D >> G;
    vector<int> p(D), c(D);
    for (int i = 0; i < D; ++i) {
        cin >> p[i] >> c[i];
    }
    int ans = INF;
    for (int bit = 0; bit < (1 << D); ++bit) {
        int sum = 0;
        int now = 0;
        for (int i = 0; i < D; ++i) {
            if (bit & (1 << i)) {
                sum += 100 * p[i]*(i+1) + c[i];
                now += p[i];
            }
        }
        for (int j = D; j--;) {
            if (bit & (1 << j))continue;
            for (int k = 0; (k<p[j]&&sum<G); ++k) {
                sum += 100 * (j + 1);
                ++now;
            }
        }
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}
