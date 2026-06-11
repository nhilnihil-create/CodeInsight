#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    ll n, k;
    cin >> n >> k;
    vector<bool> flg(n, false);
    if ( k == 0 ) {
        cout << n * n << endl;
        return 0;
    }
    ll ans = 0;
    for ( ll b = k + 1; b <= n ; b++ ) {
        ll tmp_a = k;
        while(1) {
            if ( tmp_a > n ) break;
            if ( tmp_a + ( b - k - 1) > n ) {
                ans += n - tmp_a + 1;
            }
            else {
                ans += b - k;
            }  
            tmp_a += b;
        }
//        cout << b << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
