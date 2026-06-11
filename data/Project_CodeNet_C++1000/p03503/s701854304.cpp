#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstring>

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using PP = pair<ll, pair<ll,ll>>;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

ll n, sum, m = -10000000009;
//              01234567890
ll f[100][10], p[100][11];
ll o[10];
ll c[100];

int main() {
    cin >> n;
    rep(i,n) rep(j,10) cin >> f[i][j];
    rep(i,n) rep(j,11) cin >> p[i][j];

    for (ll i = 1; i < 1024; ++i){
        rep(j,10) o[j] = (i>>j)&1;

        rep(j,n) c[j] = 0;
        sum = 0;

        rep(j,10){
            rep(k,n){
                if (o[j] == 1 && f[k][j] == 1) c[k]++;
            }
        }

        rep(j,n){
            sum += p[j][c[j]];
        }

        if (m < sum) m = sum;
    }

    cout << m << endl;

    return 0;
}