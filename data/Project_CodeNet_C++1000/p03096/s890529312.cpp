#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int cnt[2 * MAX], dp[2 * MAX];

int main(){
    int N;
    cin >> N;
    vector<int> C(N);
    rep(i, N) {
        cin >> C[i];
        C[i]--;
    }

    cnt[C[0]] = 1;
    rep(i, N) {
        if (i < N - 1 && C[i] == C[i + 1]) continue;
        dp[i] = cnt[C[i]];
        cnt[C[i + 1]] += dp[i];
        cnt[C[i + 1]] %= MOD;
    }

    cout << dp[N - 1] << endl;
}