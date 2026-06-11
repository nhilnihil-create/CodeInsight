#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    vector<int> X(5);
    rep(i, 5) cin >> X.at(i);

    // 10の倍数にした後の合計値
    int sum = 0;
    rep(i, 5) {
        sum += (X.at(i) % 10 == 0) ? X.at(i) : (X.at(i) / 10 + 1) * 10;
    }

    // 最後の数で発生する余剰分
    int minL = MOD;
    rep(i, 5) {
        if(X.at(i) % 10 != 0) {
            minL = min(minL, X.at(i) % 10);
        }
    }

    // 最初から10の倍数の場合は余剰分が発生しない
    int ans = (minL == MOD) ? sum : sum - (10 - minL);

    cout << ans << endl;

    return 0;
}
