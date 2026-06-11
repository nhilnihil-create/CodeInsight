#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 45;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> a(N); for (int i = 0; i < N; i++) cin >> a[i];

    vector<vector<ll> > dp(2, vector<ll>(MAX + 5));

    for (int i = 0; i <= MAX; i++) {
        ll d = MAX - i, flagNum = 0;
        ll p = pow(2, d);
        for (ll ai : a) {if ((ai & p) > 0) flagNum++;}
        ll nonFlagNum = N - flagNum;
        int curBit = (K & p) > 0;
        if (dp[0][i] != 0) {
            dp[0][i+1] = max(dp[0][i+1], dp[0][i] + p * flagNum);
            dp[0][i+1] = max(dp[0][i+1], dp[0][i] + p * nonFlagNum);
        }
        if (curBit) dp[0][i+1] = max(dp[0][i+1], dp[1][i] + p * flagNum);
        dp[1][i+1] = max(dp[1][i+1], dp[1][i] + p * (curBit ? nonFlagNum : flagNum));
    }

    cout << max(dp[0][MAX+1], dp[1][MAX+1]) << '\n';
}
