#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<bool> dp(K + 1);
    // dp[i]:=石がi個からスタートしたときどちらが勝つか 1:=First
    dp[0] = 0;
    for(int i = 0; i <= K; i++) {
        bool nim = 0;
        for(int j = 0; j < N; j++) {
            if(i - A[j] >= 0)
                nim |= !dp[i - A[j]];
        }
        dp[i] = nim;
    }
    if(dp[K]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}