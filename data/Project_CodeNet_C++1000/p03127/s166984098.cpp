#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;
 
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; } 
int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i, 0, n)cin >> a[i];
    ll ans = gcd(a[0], a[1]);
    rep(i, 2, n){
        ans = gcd(ans, a[i]);
    }
    cout << ans << endl;
}