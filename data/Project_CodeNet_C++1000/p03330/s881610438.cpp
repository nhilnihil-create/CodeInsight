#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i,n) for (int i = 0; i < (n); ++i)
int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> d(c, vector<int>(c));
    rep(i, c) rep(j, c) cin >> d[i][j];
    vector<vector<int>> modcnt(3, vector<int>(c, 0));
    rep(i, n) rep(j, n) {
        int tmp_c;
        cin >> tmp_c;
        --tmp_c;
        modcnt[(i+j+2)%3][tmp_c]++;
    }
    vector<vector<int>> ans(3, vector<int>(c, 0));
    rep(i, 3) rep(j, c) rep(k, c) {
        ans[i][j] += modcnt[i][k] * d[k][j];
    }
    int ans_min = 1e9;
    rep(i, c) rep(j, c) rep(k, c) {
        if ( i == j || j == k || k == i ) continue;
        ans_min = min(ans_min, ans[0][i] + ans[1][j] + ans[2][k] );
    }
    cout << ans_min << endl;
    return 0;
}