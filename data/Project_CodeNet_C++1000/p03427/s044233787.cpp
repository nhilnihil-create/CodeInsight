#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    ll n;
    cin >> n;
    auto cnt_digit = [] (ll x) -> ll {
        ll res = 0;
        while(x != 0) {
            res += x % 10;
            x /= 10;
        }
        return res;
    };
    ll ans = cnt_digit(n);
    ll fac = 10;
    while(fac <= n) {
        ll tmp = cnt_digit(n - (n % fac)-1);
        // cout << tmp << endl;
        ans = max(ans, tmp);
        fac *= 10;
    }
    cout << ans << endl;
    return 0;
}
