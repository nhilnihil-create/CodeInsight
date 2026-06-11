#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n, y;
    cin >> n >> y;

    rep(i, n+1){
        rep(j, n+1){
            if ((y - 10000 * i - 5000*j) % 1000 == 0){
                ll c = (y - 10000 * i - 5000*j) / 1000;
                if (c >= 0 && i + j + c == n){
                    cout << i << " " << j << " " << c << endl;
                    return 0;
                }
            }
        }
    }

    puts("-1 -1 -1");

    return 0;
}
