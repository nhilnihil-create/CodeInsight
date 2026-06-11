#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N;
    cin >> N;
    vector<double> x(N);
    vector<string> u(N);
    rep(i, N) cin >> x.at(i) >> u.at(i);

    double ans;
    rep(i, N) {
        if (u.at(i) == "JPY") {
            ans += x.at(i);
        } else {
            ans += x.at(i) * 380000.0;
        }
    }

    cout << fixed << setprecision(8) << ans << endl;

    return 0;
}
