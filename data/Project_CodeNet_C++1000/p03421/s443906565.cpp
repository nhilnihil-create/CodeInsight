#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

int LIS(vi as) {
    int n = as.size();
    vi dp(n + 1, 1e9);
    for (int a : as) {
        *lower_bound(dp.begin(), dp.end(), a) = a;
    }
    for (int i = 0; i <= n; i++) {
        if (dp[i] == 1e9) return i;
    }
    return -1;
}

int LDS(vi as) {
    reverse(as.begin(), as.end());
    return LIS(as);
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (n > 1l * a * b || n + 1 < a + b) {
        cout << -1 << endl;
        return 0;
    }

    vvi ret;
    vi tmp;
    for (int i = 0; i < a; i++) {
        tmp.push_back(i);
    }
    ret.push_back(tmp);
    tmp.clear();
    int k = a;
    int cnt = b - 1;
    int nokori = n - a;
    for (int j = k; j < n; j++) {
        tmp.push_back(j);
        if (tmp.size() == (nokori + cnt - 1) / cnt) {
            ret.push_back(tmp);
            nokori -= tmp.size();
            tmp.clear();
            cnt--;
        }
    }
    ret.push_back(tmp);
    reverse(ret.begin(), ret.end());
    vi ans;
    for (vi &t : ret) {
        for (int a : t) {
            ans.push_back(a + 1);
        }
    }

    for (int a : ans) {
        cout << a << ' ';
    }
    cout << '\n';

    // assert(LIS(ans) == a);
    // assert(LDS(ans) == b);
}
