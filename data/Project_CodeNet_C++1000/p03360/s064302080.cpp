#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main(void) {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    vector<ll> xs = {a, b, c};
    sort(xs.begin(), xs.end());

    ll ans = 0;
    ans += xs[0];
    ans += xs[1];

    ll x = xs[2];
    for (int i = 0; i < k; i++) {
        x = x * 2;
    }
    ans += x;

    cout << ans << endl;

    return 0;
}
