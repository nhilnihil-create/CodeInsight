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
    ll A, B;
    cin >> A >> B;

    vector<int> digits;
    ll twos = 1;
    for (int i = 0; i < 42; i++) {
        ll one_cnt = 0;

        if (i == 0) {
            one_cnt = (B + 1) / 2 - A / 2;
        } else {
            // ll f_low = (i == 0) ? (A + 1) : ((((A + 1) + twos - 1) / twos) * twos);
            ll f_low = (((A + 1) + twos - 1) / twos) * twos;
            if ((f_low & twos) == 0) {
                one_cnt += f_low - A;
            }

            ll c_high = (B / twos) * twos;
            if (c_high & twos) {
                one_cnt += B - c_high + 1;
            }

            if (B - A < twos && (A & twos) && (B & twos)) {
                one_cnt -= twos;
            }
        }

#ifdef DEBUG
        printf("i: %d, one_cnt: %lld\n", i, one_cnt);
#endif

        if (one_cnt % 2 == 1) {
            digits.push_back(1);
        } else {
            digits.push_back(0);
        }

        twos *= 2;
    }

    reverse(digits.begin(), digits.end());

#ifdef DEBUG
    printf("0b");
    for (int i = 0; i < (int) digits.size(); i++) {
        cout << digits[i];
    }
    cout << endl;
#endif

    ll ans = 0;
    for (int i = 0; i < (int) digits.size(); i++) {
        ans *= 2;
        if (digits[i]) {
            ans += 1;
        }
    }
    cout << ans << endl;

    return 0;
}
