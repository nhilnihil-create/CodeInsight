#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    int n, q;
    cin >> n >> q;
    vector<char> s(n);
    REP(i, n) cin >> s[i];
    vector<char> c(q), t(q);
    REP(i, q) cin >> c[i] >> t[i];
    
    int ans = n;
    
    int left = -1, right = n;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        int now = mid;
        bool flag = false;
        REP(i, q) {
            if (c[i] == s[now]) {
                if (t[i] == 'L') --now;
                else ++now;
                if (now == -1) {
                    flag = true;
                    break;
                }
                if (now == n) {
                    break;
                }
            }
        }
        if (flag) left = mid;
        else right = mid;
    }
    ans -= right;
    
    left = -1; right = n;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        int now = mid;
        bool flag = false;
        REP(i, q) {
            if (c[i] == s[now]) {
                if (t[i] == 'L') --now;
                else ++now;
                if (now == -1) {
                    break;
                }
                if (now == n) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) right = mid;
        else left = mid;
    }
    ans -= (n - right);
    
    cout << ans << "\n";
    
    return 0;
}
