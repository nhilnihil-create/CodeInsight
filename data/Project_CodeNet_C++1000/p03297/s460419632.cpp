#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
int mmod(int n, int m) {
    return (n % m + m) % m;
}   
void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (a < b || d < b) {
        cout << "No\n";
        return;
    }   
    int l = c + 1 - b;
    int mod = __gcd(b, d);
    if (mmod(l, mod) <= mmod(a, mod)) l += mmod(a, mod) - mmod(l, mod);
    else l += mod - (mmod(l, mod) - mmod(a, mod));
    if (l < 0) cout << "No\n";
    else cout << "Yes\n";
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t; cin >> t;
    while (t--) solve();
}