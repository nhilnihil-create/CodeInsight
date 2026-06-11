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

ll n, y;

int main() {
    cin >> n >> y;
    rep(i,n+1){
        rep(j,n-i+1){
            ll k = n-(i+j);
            ll m = i*10000 + j*5000 + k*1000;
            if (m == y){
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}