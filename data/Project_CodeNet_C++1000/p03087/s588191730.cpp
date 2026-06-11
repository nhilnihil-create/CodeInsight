#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    // 累積和の前処理
    vector<int> sum(N + 1, 0);
    for (int i = 1; i < N; ++i) {
        sum[i+1] = sum[i];
        if (S[i-1] == 'A' && S[i] == 'C')
            sum[i+1]++;
    }

    int l, r;
    int ans;
    rep(q, Q) {
        cin >> l >> r;
        ans = sum[r] - sum[l];
        cout << ans << endl;
    }

    return 0;
}
