#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

#define fori(a, n) for(ll (a) = 0; a < (n); ++a)
#define forI(a, n) for(ll (a) = 1; a <= (n); ++a)
#define pll pair<ll, ll>
#define pt pair<ll, ll>
#define x first
#define ff first
#define y second
#define ss second

const ll MAXN = 5e5 + 1;
const ll INF = 9e18;
const ll mod = 1e9 + 7;

ll n, m;

ll dp[3001][3001];
ll sm[3001][3001];

void solve(){
    string s;
    cin >> n >> s;
    dp[1][1] = 1;
    forI(i, n) sm[1][i] = 1;
    for(ll i = 2; i <= n; ++i){
        if (s[i - 2] == '<') {
            forI(j, i) dp[i][j] = sm[i - 1][j - 1];
        } else {
            forI(j, i) dp[i][j] = (sm[i - 1][i - 1] - sm[i - 1][j - 1] + mod) % mod;
        }
        forI(j, n) sm[i][j] = (sm[i][j - 1] + dp[i][j]) % mod;
    }
    cout << sm[n][n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input2.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
