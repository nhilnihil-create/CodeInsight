#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> A(M);
    rep(i, M) cin >> A.at(i);

    int leftCount = 0;
    int rightCount = 0;
    rep(i, M) {
        if (A.at(i) < X) {
            leftCount++;
        } else {
            rightCount++;
        }
    }

    int ans = min(leftCount, rightCount);

    cout << ans << endl;

    return 0;
}
