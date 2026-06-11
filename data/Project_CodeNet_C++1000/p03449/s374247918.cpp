#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    rep(i, 2) {
        rep(j, n) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    rep(i, n) {
        int sum = 0;
        rep(j, i + 1) {
            sum += a[0][j];
        }
        repl(j, i, n) {
            sum += a[1][j];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
