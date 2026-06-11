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
    int N, K;
    cin >> N >> K;

    map<int, ll> m;
    for (int i = 1; i <= N; i++) {
        m[i % K]++;
    }

    ll ans = m[0] * m[0] * m[0];
    if (K % 2 == 0) {
        ans += m[K / 2] * m[K / 2] * m[K / 2];
    }

    cout << ans << endl;
    return 0;
}
