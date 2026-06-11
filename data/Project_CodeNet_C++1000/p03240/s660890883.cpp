#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    ll n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> h(n);
    rep(i, n) cin >> x[i] >> y[i] >> h[i];
    rep(xi, 101) rep(yi, 101) {
        ll hmax = 1e18;
        ll hmin = -1;
        rep(i, n) {
            ll sa = abs(x[i]-xi) + abs(y[i]-yi);
            if (h[i] == 0) {
                hmax = min(hmax, sa);
            }
            else {
                hmin = max(hmin, h[i]+sa);
                hmax = min(hmax, h[i]+sa);
            }
        }
        if (hmax == hmin) {
            printf("%d %d %lld\n", xi, yi, hmin);
            return 0;
        }
    }
}
