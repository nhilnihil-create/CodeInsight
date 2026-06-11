#include <bits/stdc++.h>

#define pb push_back
#define PQ priority_queue
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

typedef long long ll;
typedef long double ld;

//__builtin_popcount(x)

using namespace std;

const int mod = 1e9 + 7;

ll add(ll a, ll b) {
    ll res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

ll sub(ll a, ll b) {
    ll res = a - b + mod;
    if (res >= mod) res -= mod;
    return res;
}

ll mul(ll a, ll b) {
    return (((a % mod) * (b % mod)) % mod);
}

/* Z-FUNCTION
ll l = 0, r = 0, n = (int)s.size();
vector<int> z(n, 0);
for (int i = 1; i < n; i++) {
    if (r >= i) {
        z[i] = min(1ll*z[i-l], r-i+1);
    }
    while (z[i] + i < n && s[z[i]] == s[z[i] + i]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
}
*/

/*vector<int> find_dividers(int x) {
    vector<int> dividers;

    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
           dividers.push_back(i);
            if (i * i != x) {
                dividers.push_back(x / i);
            }
        }
    }

    return dividers;
}*/

/*int nok(int a, int b) {
    return a / __gcd(a, b) * b;
}*/

void solve() {
    string s, t;
    cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    vector<vector<int>> dp(n+1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] != t[j-1]) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            } else {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }

    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) {
            ans.pb(s[i-1]);
            i--, j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else j--;
    }

    reverse(ans.begin(), ans.end());
    cout << ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
