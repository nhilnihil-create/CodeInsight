#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll r, g, b, n;
    cin >> r >> g >> b >> n;
    ll ans = 0;

    rep(i, n+1){
        rep(j, n+1){
            ll r_num = i;
            ll g_num = j;
            ll b_num = (n - r_num*r - g_num*g) / b;
            ll b_mod = (n - r_num*r - g_num*g) % b;
            if (b_mod == 0 && b_num >= 0 && b_num <= 3000){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
