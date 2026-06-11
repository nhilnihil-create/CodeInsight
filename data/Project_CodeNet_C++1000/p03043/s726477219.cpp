#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n, k;
    cin >> n >> k;

    double ans = 0;

    rep(i, n){
        ll point = i+1;
        ll cnt = 0;
        double h = 1.0;
        while(true){
            if (point >= k){
                break;
            }
            cnt++;
            h /= 2.0;
            point *= 2;
        }
        ans += 1.0 / double(n) * h;
    }

    cout << std::fixed << std::setprecision(20) << ans << endl;

    return 0;
}
