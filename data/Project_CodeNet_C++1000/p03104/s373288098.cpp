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
        ll one_cnt_a = 0, one_cnt_b = 0;

        one_cnt_a += (A - 1) / (twos * 2) * twos;
        one_cnt_a += max(0LL, (A - 1) - (((A - 1) / (twos * 2) * (twos * 2)) + twos) + 1);

        one_cnt_b += B / (twos * 2) * twos;
        one_cnt_b += max(0LL, B - ((B / (twos * 2) * (twos * 2)) + twos) + 1);

#ifdef DEBUG
        printf("i: %d, one_cnt_a: %lld, one_cnt_b: %lld\n", i, one_cnt_a, one_cnt_b);
#endif

        ll one_cnt = one_cnt_b - one_cnt_a;

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
