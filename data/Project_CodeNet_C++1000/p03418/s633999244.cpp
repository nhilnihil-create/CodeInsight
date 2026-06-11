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
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    for (ll b = K + 1; b <= N; b++) {
        ans += (N / b) * (b - K);
        ans += max(0LL, (N % b) + 1 - K);
        // printf("b: %lld, ans: %lld\n", b, ans);
        if (K == 0) {
            ans--; // for a = 0
        }
    }

    cout << ans << endl;

    return 0;
}
