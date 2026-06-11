#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

ll match[10] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
string dp[11000];

const string MINUSINF = "-";

void chmax_str(string &a, string b) {
    if (a == MINUSINF) a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size()) {
        if (a < b) a = b;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    rep(i, M) cin >> A[i];

    rep(i, 11000) dp[i] = MINUSINF;
    dp[0] = "";

    rep(i, N) {
        if (dp[i] == MINUSINF) continue;
        for (auto a: A) {
            chmax_str(dp[i + match[a - 1]], dp[i] + (char) ('0' + a));
        }
    }
    cout << dp[N] << endl;
}