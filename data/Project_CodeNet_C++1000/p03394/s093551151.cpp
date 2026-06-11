// Template
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
#include <complex>
#include <cassert>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, r) for (int i = (l); i < (r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <typename T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET{IOSET(){cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Main Code
int main() {
    int n;
    cin >> n;
    
    if (n == 3) {
        cout << "2 5 63\n";
        return 0;
    }
    if (n == 4) {
        cout << "2 5 20 63\n";
        return 0;
    }
    if (n == 6) {
        cout << "2 4 6 8 5 15\n";
        return 0;
    }
    if (n == 19999) {
        rep(i, 15000) {
            if (i == 2) continue;
            cout << 2 * (i + 1) << " ";
        }
        rep(i, 5000) cout << 3 * (i * 2 + 1) << " \n"[i == 4999];
        return 0;
    }
    
    for (int i = 3; i < n; i += 3) {
        int j = n - i;
        if (j & 1) continue;
        if ((j * 2 - 1) * 3 > 30000) continue;
        if (i * 2 > 30000) continue;
        rep(k, i) cout << 2 * (k + 1) << " ";
        rep(k, j) cout << 3 * (k * 2 + 1) << " \n"[k == j - 1];
        break;
    }
    return 0;
}
