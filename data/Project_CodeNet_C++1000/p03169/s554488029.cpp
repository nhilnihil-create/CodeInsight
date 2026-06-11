#include <bits/stdc++.h>

using namespace std;

constexpr int ms = 303;

double dp[ms][ms][ms];

void solve() {
    int n;
    cin >> n;

    vector<int> sushi(4, 0);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        ++sushi[k];
    }

    for (int i = 0; i < ms; ++i)
        for (int j = 0; j < ms; ++j)
            for (int k = 0; k < ms; ++k)
                dp[i][j][k] = -1.0;

    function<double(int, int, int)> calc_dp = [&] (int one, int two, int three) {
        if (one == 0 && two == 0 && three == 0) {
            return 0.0;
        }

        if (dp[one][two][three] != -1) {
            return dp[one][two][three];
        }

        double total = (double) (one+two+three);
        double num_op = ((double) n) / total;
        double ans = num_op;

        if (one > 0) {
            ans += (((double) one) / total) * calc_dp(one-1, two, three);
        }
        if (two > 0) {
            ans += (((double) two) / total) * calc_dp(one+1, two-1, three);   
        }
        if (three > 0) {
            ans += (((double) three) / total) * calc_dp(one, two+1, three-1);   
        }

        dp[one][two][three] = ans;
        return ans;
    };
    
    printf("%.10lf\n", calc_dp(sushi[1], sushi[2], sushi[3]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}
