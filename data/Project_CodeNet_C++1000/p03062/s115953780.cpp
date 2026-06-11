#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

const ll LLINF = -100100100;


int main() {
    int n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(2, LLINF));
    dp[0][0] = 0;
    dp[0][1] = LLINF;
    rep(i, n) {
        dp[i + 1][0] = max(dp[i][0] + A[i], dp[i][1] - A[i]);
        dp[i + 1][1] = max(dp[i][0] - A[i], dp[i][1] + A[i]);
    }
    cout << dp[n][0] << endl;

    return 0;
}