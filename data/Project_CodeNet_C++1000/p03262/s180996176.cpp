#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll n, x;
    cin >> n >> x;
    ll t;
    cin >> t;
    ll ans = 0;
    ans = abs(t-x);
    rep(i,n-1){
        cin >> t;
        ans = __gcd(ans, abs(t-x));
    }
    cout << ans << endl;
    return 0;
}