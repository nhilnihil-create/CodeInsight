#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

string ans = "";
ll sum[40] = {};

void rec (int i, int n) {
    if (i == 0) {
        if (n == 0) ans += "0";
        else if (n == 1)
            ans += "1";
        else {
            cout << "no";
        }
        return;
    }

    if (sum[i] - pow (2, i - 1) < n) {
        n -= pow (2, i);
        ans += "10";
        // cout << n << "\n ";
        rec (i - 2, n);
    } else if (sum[i - 2] < n) {
        n -= pow (2, i - 1);
        ans += "11";
        // cout << n << "\n ";
        rec (i - 2, n);
    } else if ((sum[i - 3] <= n && i > 3) || i == 2 && (n == 0 || n == 1)) {
        ans += "00";
        // cout << n << "\n ";
        rec (i - 2, n);
    } else {
        ans += "01";
        n += pow (2, i - 1);
        // cout << n << "\n ";
        rec (i - 2, n);
    }
}
int main() {
    int n;
    cin >> n;
    int cnt = -1;
    bool chk1 = 0, chk2 = 0;
    if (n >= 0) chk1 = 1;
    else
        chk2 = 1;
    rep (i, 0, 40) {
        if (i == 0) sum[i] = 1;
        else if (i == 1)
            sum[i] = -2;
        else if (i % 2 == 0)
            sum[i] = sum[i - 2] + pow (-2, i);
        else
            sum[i] = sum[i - 2] + pow (-2, i);

        if (sum[i] >= n && cnt == -1 && chk1) {
            cnt = i;
        } else if (sum[i] <= n && cnt == -1 && chk2) {
            cnt = i + 1;
        }
    }
    // cout << cnt << "\n";
    rec (cnt, n);
    if (n != 0 && ans[0] == '0') ans = ans.substr (1, cnt);
    cout << ans << "\n";
}
