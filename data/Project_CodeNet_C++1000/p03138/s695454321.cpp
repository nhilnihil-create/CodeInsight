#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<lint>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n;
    lint k;
    cin >> n >> k;
    vec a(n);
    rep(i, n) cin >> a[i];

    lint l = k;
    int cnt = -1;
    while (l > 0) {
        l >>= 1;
        cnt++;
    }

    lint res = 0;
    bool smaller = false;

    for (int i = 60; i >= 0; --i) {
        lint base = 1LL << i;
        if (i > cnt) {
            int cnt2 = 0;
            rep(j, n) {
                if ((a[j] >> i) & 1) cnt2++;
            }
            res += base * cnt2;
        }
        else {
            int nd = (k >> i) & 1;
            int cnt1 = 0;
            rep(j, n) {
                if ((a[j] >> i) & 1) cnt1++;
            }
            int cnt0 = n - cnt1;
            if (cnt1 >= cnt0) {
                if (nd) smaller = true;
                res += base * cnt1;
            }
            else {
                if (smaller) {
                    res += base * cnt0;
                }
                else {
                    if (nd) res += base * cnt0;
                    else res += base * cnt1;
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}