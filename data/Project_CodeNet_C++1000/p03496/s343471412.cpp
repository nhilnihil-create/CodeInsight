#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
const ll INF = 1e9;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i ++) cin >> a[i];

    ll m = INF;
    int idx_m = -1;
    ll M = -INF;
    int idx_M = -1;
    for (int i = 0; i < n; i ++) {
        if (M < a[i]) {
            M = a[i];
            idx_M = i;
        }
        if (m > a[i]) {
            m = a[i];
            idx_m = i;
        }
    }

    vector<pint> ans;
    bool flag = false;

    if (m < 0 && M > 0) {
        if (abs(m) <= abs(M)) flag = true;
    }
    if (m >= 0) flag = true;


    if (flag) {
        for (int i = 0; i < n; i ++) {
            if (a[i] < 0) {
                a[i] += M;
                ans.push_back({idx_M + 1, i + 1});
            }
        }
        for (int i = 0; i < n - 1; i ++) {
            if (a[i] > a[i + 1]) {
                a[i + 1] += a[i];
                ans.push_back({i + 1, i + 2});
            }
        }
    }   

    else {
        for (int i = 0; i < n; i ++) {
            if (a[i] > 0) {
                a[i] += m;
                ans.push_back({idx_m + 1, i + 1});
            }
        }
        for (int i = n - 2; i >= 0; i --) {
            if (a[i] > a[i+1]) {
                a[i] += a[i+1];
                ans.push_back({i + 2, i + 1});
            }
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i].first << ' ' << ans[i].second << endl; 
    }
}