#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define reps(i, n) for (int i = 0; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;

const string MS = "-";
void chmax(string &a, string b) {
    if (a == MS) a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size()) {
        if (a < b) a = b;
    }
}

ll match[10] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
string dp[10101];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    vector<int> A(M);
    rep(i, M) cin >> A[i];
    rep(i, 10101) dp[i] = MS;
    dp[0] = "";
    reps(i, N) {
        if (dp[i] == MS) continue;
        for (auto a : A) {
            chmax(dp[i+match[a-1]], dp[i] + (char)('0' + a));
        }
    }
    cout << dp[N] << endl;
    return 0;
}