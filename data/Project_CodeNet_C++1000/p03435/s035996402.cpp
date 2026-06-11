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

ll x[2], y[2];
ll c[3][3];

int main() {
    rep(i,3) rep(j,3) cin >> c[i][j];
    rep(i,2){
        x[i] = c[i+1][0]-c[i][0];
        y[i] = c[0][i+1]-c[0][i];
    }
    rep(i,2){
        rep(j,2){
            if (c[j+1][i+1] - c[j][i+1] != x[j] || c[i+1][j+1] - c[i+1][j] != y[j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}