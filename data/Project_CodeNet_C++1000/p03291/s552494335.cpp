#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define ln '\n'

using namespace std;
using LL = long long;
using ldouble = long double;
using P = pair<int, int>;
using LP = pair<LL, LL>;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1e9 + 7;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<LL> Div(LL n) {
    vector<LL> ret;
    for(LL i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);
            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

LL dp[SIZE][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    dp[0][0] = 1;
    for(int i = 0; i < s.size(); ++i) {
        for(int j = 0; j < 4; ++j) {
            if(s[i] == '?') dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * 3) % MOD;
            else dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;

        }
        if(s[i] == 'A' || s[i] == '?') dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % MOD;
        if(s[i] == 'B' || s[i] == '?') dp[i + 1][2] = (dp[i + 1][2] + dp[i][1]) % MOD;
        if(s[i] == 'C' || s[i] == '?') dp[i + 1][3] = (dp[i + 1][3] + dp[i][2]) % MOD;

    }
    cout << dp[s.size()][3] << endl;
    return 0;
}

