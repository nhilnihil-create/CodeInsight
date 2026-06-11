#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
// ans = x + (1-p)*ans ans = x/p
// p = 1/2^m x = 1900m + 100(n-m)
int main() {
    ll n, m;
    cin >> n >> m;
    ll time = 1900LL * m + 100L * (n-m);
    ll k = 1LL<<m;
    ll ans = time * k;
    cout << ans << endl;
    return 0;
}