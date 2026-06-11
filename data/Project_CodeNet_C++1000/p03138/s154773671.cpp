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

const int MAX_BITS = 63;
const ll INF = LONG_LONG_MAX / 2;

vector<ll> as;
vector<ll> ones; // {0, ones at the MSB, ..., ones at the LSB}

vector<ll> dp1, dp2;

void calc_ones() {
    ones.push_back(0);
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        int cnt = 0;
        for (auto &a : as) {
            if (a & (1LL << i)) cnt++;
        }
        ones.push_back(cnt);
    }
}

void solve(const ll N, const ll K) {
    for (int i = 1; i <= MAX_BITS; i++) {
        ll d_of_k = (K & (1LL << (MAX_BITS - i)));
        // printf("i: %d, d_of_k: %lld\n", i, d_of_k);

        // dp1
        if (d_of_k) {
            if (ones[i] * 2 >= N) {
                chmax(dp2[i], dp1[i - 1] + ones[i] * (1LL << (MAX_BITS - i)));
            }
            chmax(dp1[i], dp1[i - 1] + (N - ones[i]) * (1LL << (MAX_BITS - i)));
        } else {
            chmax(dp1[i], dp1[i - 1] + ones[i] * (1LL << (MAX_BITS - i)));
        }

        // dp2
        if (dp2[i - 1] > 0) {
            if (ones[i] * 2 >= N) {
                chmax(dp2[i], dp2[i - 1] + ones[i] * (1LL << (MAX_BITS - i)));
            }
            chmax(dp2[i], dp2[i - 1] + (N - ones[i]) * (1LL << (MAX_BITS - i)));
        }
    }
}

int main(void) {
    ll N, K;
    cin >> N >> K;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    calc_ones();
    // cout << "ones: ";
    // for (auto &one : ones) {
    //     cout << one << " ";
    // }
    // cout << endl;

    dp1.resize(MAX_BITS + 1, -INF);
    dp2.resize(MAX_BITS + 1, -INF);
    dp1[0] = 0;
    dp2[0] = 0;

    solve(N, K);

    // printf("dp1: \n");
    // for (auto &x : dp1) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // printf("dp2: \n");
    // for (auto &x : dp2) {
    //     cout << x << " ";
    // }
    // cout << endl;

    cout << max(dp1[MAX_BITS], dp2[MAX_BITS]) << endl;

    return 0;
}
