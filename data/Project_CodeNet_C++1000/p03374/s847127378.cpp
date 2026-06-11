#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (signed i = 0; i < (n); i++)
#define REP(i, s, n) for (signed i = (s); i < (n); i++)
#define int long long

signed main() {
    int N, C;
    cin >> N >> C;
    vector<int> x(N), v(N), r_max(N), l_max(N);
    rep(i, N) cin >> x[i] >> v[i];
    
    int cal_r = 0, cal_l = 0;
    int ans = 0;
    rep(i, N) {
        int j = N - i - 1;
        cal_r += v[i];
        cal_l += v[j];
        int pre_r = i >= 1 ? r_max[i - 1] : 0;
        r_max[i] = max(pre_r, cal_r - x[i]);
        int pre_l = i >= 1 ? l_max[i - 1] : 0;
        l_max[i] = max(pre_l, cal_l - (C - x[j]));
        ans = max({ans, r_max[i], l_max[i]});
    }
    
    rep(i, N - 1) {
        int j = N - i - 1;
        int r = r_max[i] + l_max[N - i - 2] - x[i];
        int l = l_max[i] + r_max[N - i - 2] - (C - x[j]);
        ans = max({ans, r, l});
    }
    
    cout << ans << endl;
}