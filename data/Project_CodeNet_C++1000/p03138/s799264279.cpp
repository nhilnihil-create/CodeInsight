#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

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

const int MSB_POS = 40;

vector<ll> as;
vector<ll> ones;

void calc_ones() {
    for (int i = MSB_POS; i >= 0; i--) {
        ll cnt = 0;
        for (auto &a : as) {
            if (a & (1LL << i)) {
                cnt++;
            }
        }
        ones[i] = cnt;
    }
}

ll solve(const ll N, const ll K) {
    ll ans = 0;

    // candidate with K
    for (int j = MSB_POS; j >= 0; j--) {
        bool has_bit_k = (K & (1LL << j)) != 0;
        if (has_bit_k) {
            ans += (N - ones[j]) * (1LL << j);
        } else {
            ans += ones[j] * (1LL << j);
        }
    }

    for (int i = MSB_POS; i >= 0; i--) {
        ll d_of_k = (K & (1LL << i));
        if (d_of_k == 0) continue;

        ll acc = 0;

        // above i
        for (int j = MSB_POS; j > i; j--) {
            bool has_bit_k = (K & (1LL << j)) != 0;
            if (has_bit_k) {
                acc += (N - ones[j]) * (1LL << j);
            } else {
                acc += ones[j] * (1LL << j);
            }
        }

        // at i
        acc += ones[i] * (1LL << i);

        // below i
        for (int j = i - 1; j >= 0; j--) {
            acc += max(ones[j], N - ones[j]) * (1LL << j);
        }

        chmax(ans, acc);
    }

    return ans;
}

int main(void) {
    ll N, K;
    cin >> N >> K;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    ones.resize(MSB_POS + 1);
    calc_ones();

    cout << solve(N, K) << endl;

    return 0;
}
