#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T &a, T b) {if(a<b) {a=b;return 1;} return 0;}

const int max_digit = 50;
ll dp[100][2];

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    rep(d,max_digit) {
        ll mask = 1LL << (max_digit - d - 1);

        int num = 0;
        rep(i,n) if (a[i] & mask) num++;

        ll cost0 = mask * num;
        ll cost1 = mask * (n-num);

        //exact -> exact
        if (dp[d][0] != -1) {
            if (k & mask) chmax(dp[d+1][0], dp[d][0] + cost1);
            else chmax(dp[d+1][0],dp[d][0] + cost0);
        }
        //exact -> smaller
        if (dp[d][0] != -1) {
            if (k & mask) chmax(dp[d+1][1], dp[d][0] + cost0);
        }
        //smaller -> smaller
        if (dp[d][1] != -1) {
            chmax(dp[d+1][1], dp[d][1] + cost0);
            chmax(dp[d+1][1], dp[d][1] + cost1);
        }
    }
    cout << max(dp[max_digit][0],dp[max_digit][1]) << endl;
}