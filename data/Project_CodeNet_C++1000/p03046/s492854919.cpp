#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define reps2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int m, k, n;
bool solve(vector<int> &ans) {
    if (m == 0) {
        if (k == 0) {
            ans = vector<int>({0, 0});
            return true;
        }
        return false;
    } else if (m == 1) {
        if (k == 0) {
            ans = vector<int>({0, 0, 1, 1});
            return true;
        }
        return false;
    }
    if (k >= pow(2, m)) {
        return false;
    }
    rep(i, n) {
        if (i != k) {
            ans.push_back(i);
        }
    }
    ans.push_back(k);
    rrep(i, n) {
        if (i != k) {
            ans.push_back(i);
        }
    }
    ans.push_back(k);
    return true;
}

int main() {
    cin >> m >> k;
    n = pow(2, m);
    vector<int> ans;
    if (!solve(ans)) {
        cout << -1 << endl;
    } else {
        rep(i, ans.size()) {
            if (i) {
                cout << " ";
            }
            cout << ans[i];
        }
    }
    cout << endl;
    return 0;
}