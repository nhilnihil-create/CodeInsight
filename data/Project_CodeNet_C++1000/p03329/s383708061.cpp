/*
　　こんにちは。あたしはｶｳｶﾞｰﾙ。
　　RedcoderになるためAtCoderを巡る旅をしてます。

　　　 　＿_
　　　 ヽ|＿_|ノ　　　　ﾓｫ
　　　　||‘‐‘||ﾚ　　_)_, ―‐ 、
　　　　/(Ｙ (ヽ＿ /・ ヽ　　   ￣ヽ
　　　　∠ ＿ ゝ　 ｀^ヽ ﾉ.::::_(ノヽ
　　　　 _/ヽ　 　　  /ヽ￣￣￣/ヽ
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dump(x) cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl

#define rep(i, n) REP(i, 0, n)                  // 0, 1, ..., n-1
#define REP(i, x, n) for(int i = x; i < n; i++) // x, x + 1, ..., n-1
#define FOREACH(x, a) for(auto &(x) : (a))

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()

#define COUT(x) cout << (x) << endl

template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

ll dp[110000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    rep(i, 110000) dp[i] = N;
    dp[0]                = 0;
    rep(i, N) {
        for(int pow6 = 1; i + pow6 <= N; pow6 *= 6) {
            chmin(dp[i + pow6], dp[i] + 1);
        }
        for(int pow9 = 1; i + pow9 <= N; pow9 *= 9) {
            chmin(dp[i + pow9], dp[i] + 1);
        }
    }
    COUT(dp[N]);
}
