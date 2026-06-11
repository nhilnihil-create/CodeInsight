#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(i, a) for(auto& i: a)
// #define int long long
using namespace std;
using ll = long long;

// GLOBAL VARS START
const int INF = INT_MAX >> 2;


// GLOBAL VARS END

void solve() {
    unordered_set<int> seen;
    int n;
    cin >> n;
    vector<int> v(n);

    trav(i, v) cin >> i;
    sort(all(v));
    int ans = 0;
    int maxNum = v.back();
    rep(i, 0, n) {
        int dem = v[i];
        dem = min(dem, maxNum - dem);
        ans = max(dem, ans);
    }
    rep(i, 0, n) {
        int dem = v[i];
        if (dem == ans) {
            swap(dem, maxNum);
            cout << dem << " " << maxNum;
            return;
        } else if (dem == maxNum - ans) {
            swap(dem, maxNum);
            cout << dem << " " << maxNum;
            return;
        }
    }
}

int main() {
    int t = 1;
//    cin >> t;
    while (t--) solve();
    return 0;
}