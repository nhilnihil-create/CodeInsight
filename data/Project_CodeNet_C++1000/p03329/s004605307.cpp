/**
*    created: 27.06.2020 17:43:55
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcountll(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}

const int INF = 1LL << 60;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = n;
    vector<int> dp(100001,INF);
    dp[0] = 0;
    rep2(i,1,n+1) {
        int pow6 = 1; int pow9 = 1;
        while (pow6 <= i) {
            chmin(dp[i],dp[i-pow6]+1);
            pow6 *= 6;
        }
        while (pow9 <= i) {
            chmin(dp[i],dp[i-pow9]+1);
            pow9 *= 9;
        }
    }
    cout << dp[n] << endl;
    return 0;
}