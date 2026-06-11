#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define F first
#define S second
#define um map <ll,ll>
#define rep(i,z,n)  for(int i=z;i<n;i++)
#define repi(i,z,n) for(int i=z;i<=n;i++)
#define repn(i,z,n) for(int i=n-1;i>=z;i--)
#define vec vector<ll>
#define vecp vector<pair<ll,ll>>
#define pi (double)3.14159265358979323846
#define ld long double
#define all(z) z.begin(),z.end()

ll power(ll a, ll b, ll m) { ll ans = 1; a = a % m; if (a == 0) return 0; while (b) { if (b & 1) ans = (ans * a) % m; b /= 2; a = (a * a) % m; } return ans; }
ll modInverse(ll a, ll m) {return power(a, m - 2, m);}
ll binpow(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1)res = res * a; a = a * a; b >>= 1;} return res;}
ll binlog2(ll n) {ll logValue = -1; while (n) {logValue++; n >>= 1;} return logValue;}
void print(vec a) {rep(i, 0, a.size())cout << a[i] << " "; cout << endl;}
const ll mod = 1e9 + 7;
const ll N = 3e3 + 5;
const ll inf = 2e18;
string s, t;
ll dp[N][N];

ll recur(int i, int j) {
    if (i <= 0 || j <= 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i - 1] == t[j - 1])
        return dp[i][j] = 1 + recur(i - 1, j - 1);
    else return dp[i][j] = max(recur(i - 1, j), recur(i, j - 1));
}


void solve() {
    cin >> s >> t;
    int n, m;
    n = s.size();
    m = t.size();
    memset(dp, -1, sizeof(dp));
    recur(n, m);
    string ans;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(all(ans));
    cout << ans << endl;
}





int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    speed;
    int test = 1;
    // cin >> test;
    while (test--) {
        // cout << "Case #" << t1 << ": ";
        solve();
    }
    return 0;
}