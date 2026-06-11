#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long int
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
const int mod = 1e9 + 7;
const int mod1 = 998244353;
typedef long double f80;
#ifndef LOCAL
#define endl '\n'
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
const int N = 1e5 + 5;
int p[N], a[N];
int pwr(int a,int b){
    int ans = 1;
    while(b){
        if(b & 1) 
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void solve(){
    int n;
    cin >> n;
    fr(i, 1, n)
        cin >> a[i];
    fr(i, 1, n)
        p[i] = (p[i - 1] + pwr(i, mod - 2)) % mod;
    int ans = 0;
    fr(i, 1, n){
        ans += (p[i] * a[i]) % mod;
        ans += (p[n - i + 1] * a[i]) % mod;
        ans -= a[i];
        ans %= mod;
    }
    ans = (ans + mod) % mod;
    fr(i, 1, n) ans = (ans * i) % mod;
    cout << ans << endl;
}
signed main()
{
    IO;
    #ifdef LOCAL
        freopen("inp.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif
    clock_t clk = clock();
    int t = 1;
    // cin >> t;
    fr(i, 1, t){
        solve();
    }
    cerr << endl << setprecision(10) << fixed << (double)(clock() - clk) / CLOCKS_PER_SEC;
    return 0;
};