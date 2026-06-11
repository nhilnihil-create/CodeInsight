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
    ll x;
    cin >> n >> x;

    vector<ll>a(n);
    ll maxd=0;
    rep(i, 0, n){
        cin >> a[i];
        maxd = max(maxd, abs(x-a[i]));
    }
    if(n == 1){
        cout << abs(x-a[0]) << endl;
        return 0;
    }
    ll p = abs(a[1]-a[0]);
    rep(i, 1, n-1){
        p = gcd(p, abs(a[i+1]-a[i]));
    }
    cout << gcd(p, maxd) << endl;
}