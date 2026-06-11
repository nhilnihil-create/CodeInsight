#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr long double EPS = 1e-15;
const long double PI = acos(-1);
constexpr int inf = 1e9;
constexpr ll INF = 2e18;
constexpr ll MOD = 1e9+7;
constexpr ll MOD1 = 998244353;
typedef pair<ll,ll> P;
//#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

int n;
string s;
int q;
int k;
void solve();
void input() {
    cin >> n >> s >> q;
    REP(i,q) {
        cin >> k;
        solve();
    }
    // solve();
}

void solve() {
    ll dp[3] = {};
    ll ans = 0;
    REP(i,n) {
        if (s[i] == 'D') {
            dp[0]++;
        } else if (s[i] == 'M') {
            dp[1]++;
            dp[2] += dp[0];
        } else if (s[i] == 'C') {
            ans += dp[2];
        }
        if (i >= k - 1) {
            if (s[i - k + 1] == 'D') {
                dp[0]--;
                dp[2] -= dp[1];
            } else if (s[i - k + 1] == 'M') {
                dp[1]--;
            }
        }
    }
    cout << ans << endl;
}

int main(int argc, char *argv[]){
    input();
    // solve();
    return 0;
}
