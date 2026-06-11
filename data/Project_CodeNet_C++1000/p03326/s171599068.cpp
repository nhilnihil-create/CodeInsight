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

vector<ll> xs;
vector<ll> ys;
vector<ll> zs;

ll calc(const int bits, const int N, const int M) {
    vector<ll> values(N, 0);

    for (int i = 0; i < N; i++) {
        ll acc = 0;
        vector<ll> xyzs = {xs[i], ys[i], zs[i]};
        for (int j = 0; j < 3; j++) {
            int sign = bits & (1 << j);
            if (sign) {
                acc += xyzs[j];
            } else {
                acc -= xyzs[j];
            }
        }
        values[i] = acc;
    }

    sort(values.begin(), values.end());
    reverse(values.begin(), values.end());

    ll ans = 0;
    for (int i = 0; i < M; i++) {
        ans += values[i];
    }
    // printf("bits: %x, ans: %lld\n", bits, ans);
    return ans;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    xs.resize(N);
    ys.resize(N);
    zs.resize(N);
    for (int i = 0; i < N; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        xs[i] = x;
        ys[i] = y;
        zs[i] = z;
    }

    ll ans = 0;
    for (int bits = 0; bits < (1 << 3); bits++) {
        chmax(ans, calc(bits, N, M));
    }

    cout << ans << endl;

    return 0;
}
