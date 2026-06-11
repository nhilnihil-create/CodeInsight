#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> c(N), t(N);
    rep(i, N) cin >> c.at(i) >> t.at(i);

    int minC = 1001;
    rep(i, N) {
        if (t.at(i) <= T) {
            minC = min(minC, c.at(i));
        }
    }

    string ans = (minC == 1001) ? "TLE" : to_string(minC);

    cout << ans << endl;

    return 0;
}
