#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
typedef long long LL;

int n, pre[N][N], a[N], pre_cnt[N][N], inv[N], occ[N];
LL dp[N][N];
LL A, B, inf = 1e18;

LL solve(int pos, int kth) {
    if(pos > n) return 0;
    if(kth > (n-pos+1)) return 0;
    if(dp[pos][kth] != -1) return dp[pos][kth];
    int kth_pos = pre[pos][kth];
    int kth_inv = pre_cnt[pos][kth];
    int back_small = (kth_pos-pos) - kth_inv;
//    cout << "back_small: " << back_small << endl;
    int kth_jump = (kth-back_small);
    LL ans1 = solve(kth_pos+1, kth_jump) + A*kth_inv;
    LL ans2 = solve(pos, kth+1) + B;
//    cout << "pos: " << pos << "   kth: " << kth << " ---> " << min(ans1, ans2) << endl;
    return dp[pos][kth] = min(ans1, ans2);
}

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> A >> B;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n; i >= 1; i--) {
        occ[a[i]] = i;
        for(int j = 1; j <= n; j++) {
            if(occ[j] && j < a[i]) inv[j]++;
        }
        int kth = 0;
        for(int j = 1; j <= n; j++) {
            if(occ[j]) {
                ++kth;
                pre[i][kth] = occ[j];
                pre_cnt[i][kth] = inv[j];
            }
        }
    }
//    for(int i = 1; i <= n; i++) {
//        for(int j = 1; j <= n; j++) {
//            cout << pre_cnt[i][j] << " ";
//        }
//        cout << endl;
//    }
    memset(dp, -1, sizeof dp);
    cout << solve(1,1) << endl;

    return 0;
}

