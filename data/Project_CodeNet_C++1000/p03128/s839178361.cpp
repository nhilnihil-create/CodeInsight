#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

ll match[10] = {2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    rep(i, M) cin >> A[i];
    sort(A.rbegin(), A.rend());

    vector<int> dp(N + 100, -1);
    dp[0] = 0;

    rep(i, N + 1) {
        for (auto a: A) {
            chmax(dp[i + match[a - 1]], dp[i] + 1);
        }
    }

    string ans = "";
    int needDigit = dp[N]; // 追加する必要のある桁数
    int remain = N;
    while (remain > 0) {
        for (auto a : A) {
            if (remain - match[a - 1] < 0) continue;
            if (dp[remain - match[a - 1]] != needDigit - 1) continue;

            ans += to_string(a);
            remain -= match[a - 1];
            needDigit--;
            break;
        }
    }
    cout << ans << endl;
}