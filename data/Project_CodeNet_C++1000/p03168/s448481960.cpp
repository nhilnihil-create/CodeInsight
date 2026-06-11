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
double a[N];
vector<vector<double>> dp(N, vector<double>(N, -1));;
ll n, m;

double recur(ll i, ll h) {
    if (i > n) {
        if (h > n / 2)
            return 1;
        else
            return 0;
    }
    if (dp[i][h] != -1)
        return dp[i][h];
    double l = 0, r = 0;

    l = a[i] * recur(i + 1, h + 1);
    r = (1 - a[i]) * recur(i + 1, h);
    // cout << l << " " << r << endl;

    return dp[i][h] = (l + r);

}

void solve() {
    cin >> n;
    repi(i, 1, n)
    cin >> a[i];

    double ans = recur(1, 0);
    cout << fixed << setprecision(10) << ans << endl;
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