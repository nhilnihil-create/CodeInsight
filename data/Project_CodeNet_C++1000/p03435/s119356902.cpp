#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll c[3][3];
    rep(i, 3){
        rep(j, 3){
            cin >> c[i][j];
        }
    }

    ll a[3] = {0};
    ll b[3] = {0};
    b[0] = c[0][0] - a[0];
    b[1] = c[0][1] - a[0];
    b[2] = c[0][2] - a[0];
    a[1] = c[1][1] - b[1];
    a[2] = c[2][2] - b[2];

    rep(i, 3){
        rep(j, 3){
            if (c[i][j] != a[i] + b[j]){
                puts("No");
                return 0;
            }
        }
    }

    puts("Yes");

    return 0;
}
