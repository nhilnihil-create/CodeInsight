#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int INF = 987654321;
const ll MOD = 1e9+7;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
    string s;
    cin >> s;
    int n = sz(s);
    ll dp[100050][4] = {};
    dp[n][3] = 1;
    dp[n][2] = 0;
    dp[n][1] = 0;
    dp[n][0] = 0;
    per(i,0,n) {
        if(s[i] == '?') {
            dp[i][3] = dp[i+1][3]*3 % MOD;
        } else {
            dp[i][3] = dp[i+1][3];
        }
        rep(j,0,3) {
            if(s[i] == '?') {
                dp[i][j] += 3*dp[i+1][j];
            } else {
                dp[i][j] += dp[i+1][j];
            }
            if(s[i] == "ABC"[j] || s[i] == '?') {
                dp[i][j] += dp[i+1][j+1];
            }

            dp[i][j] %= MOD;
        }
    }
    cout << dp[0][0] << '\n';
	return 0;
}
