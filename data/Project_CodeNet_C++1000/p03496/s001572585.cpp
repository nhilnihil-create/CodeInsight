#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    long a[55]; for(int i=0; i < n; ++i) cin >> a[i];

    long cnt = 0, idx = 0, tmp = 0;
    for(int i=0; i < n; ++i) {
        if(tmp < abs(a[i])) {
            tmp = abs(a[i]);
            idx = i;
        }
    }

    vector<pair<int, int>> ans;

    if(a[idx] >= 0) {
        for(int i=0; i < n-1; ++i) {
            if(a[i] > a[i+1]) {
                a[i+1] += a[idx];
                ans.emplace_back(idx+1, i+2);
                if(a[i] > a[i+1]) {
                    a[i+1] += a[idx];
                    ans.emplace_back(idx+1, i+2);
                }

                if(a[i+1] > a[idx]) idx = i+1;
            }
        }
    } else {
        for(int i=n-1; i > 0; --i) {
            if(a[i-1] > a[i]) {
                a[i-1] += a[idx];
                ans.emplace_back(idx+1, i);
                if(a[i-1] > a[i]) {
                    a[i-1] += a[idx];
                    ans.emplace_back(idx+1, i);
                }
                if(a[i-1] < a[idx]) idx = i-1;
            }
        }
    }

    cout << ans.size() << '\n';
    for(auto p : ans) cout << p.first << " " << p.second << '\n';
    return 0;
}