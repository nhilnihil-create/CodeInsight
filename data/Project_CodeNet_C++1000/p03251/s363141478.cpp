#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> x(N), y(M);
    rep(i, N) cin >> x.at(i);
    rep(i, M) cin >> y.at(i);

    // ソート（昇順）
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    bool isExist = false;
    for (int z = X + 1; z <= Y; z++) {
        if (x.back() < z && z <= y.front()) isExist = true;
    }

    string ans = isExist ? "No War" : "War";

    cout << ans << endl;

    return 0;
}
