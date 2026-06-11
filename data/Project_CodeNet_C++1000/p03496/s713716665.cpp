#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// point : cum sum is monotonic increasing / decreasing

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    long a[55]; for(int i=0; i < n; ++i) cin >> a[i];

    int mx = 0, mn = 1e9, mxi = 0, mni = 0;
    for(int i=0; i < n; ++i) {
        if(mx < a[i]) {
            mx = a[i];
            mxi = i;
        }
        if(mn > a[i]) {
            mn = a[i];
            mni = i;
        }
    }

    vector<pair<int, int>> ans;
    if(abs(mx) >= abs(mn)) {
        for(int i=0; i < n; ++i) {
            a[i] += mx;
            ans.emplace_back(mxi + 1, i + 1);
        }

        for(int i=0; i < n-1; ++i) {
            a[i+1] += a[i];
            ans.emplace_back(i+1, i+2);
        }
    } else {
        for(int i=0; i < n; ++i) {
            a[i] += mn;
            ans.emplace_back(mni + 1, i + 1);
        }

        for(int i=n-1; i > 0; --i) {
            a[i-1] += a[i];
            ans.emplace_back(i+1, i);
        }
    }

    cout << ans.size() << '\n';
    for(auto p : ans) cout << p.first << " " << p.second << '\n';
    return 0;
}