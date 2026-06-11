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

int main() {
    ll n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    for (int d = 60; d >= -1; --d) {
        if (d != -1 && !(k & (1LL<<d))) continue;
        ll tmp = 0;
        for (int e = 60; e >= 0; --e) {
            ll mask = 1LL << e;
            ll num = 0;
            rep(i, n) if (a[i] & mask) ++num;
            if (e > d) {
                if (k & mask) {
                    tmp += mask * (n - num);
                }
                else {
                    tmp += mask * num;
                }
            }
            else if (e == d) {
                tmp += mask * num; 
            }
            else {
                tmp += mask * max(num, n-num);
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
