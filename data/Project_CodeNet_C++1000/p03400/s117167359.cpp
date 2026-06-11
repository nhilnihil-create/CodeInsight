#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N, D, X;
    cin >> N >> D >> X;
    vector<int> A(N);
    rep(i, N) cin >> A.at(i);

    int count = 0;
    rep(i, N) {      // 人
        rep(j, D) {  // 日
            if (j * A.at(i) + 1 <= D) {
                count++;
            }
        }
    }

    int ans = count + X;

    cout << ans << endl;

    return 0;
}
