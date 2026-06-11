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

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> vec;
    int cnt = 1;
    rep (i, 1, n) {
        if (s[i - 1] != s[i]) {
            vec.push_back (cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    vec.push_back (cnt);
    // cout << vec.size() << "\n";
    // rep (i, 0, vec.size()) cout << vec[i] << " ";
    // cout << "\n";
    //累積和
    int sum[vec.size()];
    sum[0] = 0;
    rep (i, 0, vec.size()) sum[i + 1] = sum[i] + vec[i];
    //計算
    if (vec.size() <= k * 2) {
        cout << n << "\n";
        return 0;
    }
    int res = 0;
    if (s[0] == '0') res = sum[k * 2];
    for (int i = s[0] == '1' ? 0 : 1; i < vec.size() - 2 * k; i += 2) {
        int ans;
        ans = sum[i + k * 2 + 1] - sum[i];
        res = max (ans, res);
    }
    res = max (res, sum[vec.size()] - sum[vec.size() - 2 * k]);
    cout << res << "\n";
}