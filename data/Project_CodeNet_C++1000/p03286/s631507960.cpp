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

int calc_high_bit(const int n) {
    int bit = 0;
    ll plus_acc = 0;
    ll minus_acc = 0;

    while (1) {
        ll diff = 1LL << bit;

        if (bit % 2 == 1) {
            diff *= -1;
        }

        if (diff > 0) {
            plus_acc += diff;
            if (n >= 0 && plus_acc >= n) {
                break;
            }
        } else {
            minus_acc += diff;
            if (n < 0 && minus_acc <= n) {
                break;
            }
        }

        bit++;
    }

    return bit;
}

int pow(int base, int n) {
    if (n == 0) {
        return 1;
    }
    return base * pow(base, n -1);
}

int main(void) {
    int N;
    cin >> N;

    int high_bit = calc_high_bit(N);
    // printf("high_bit: %d\n", high_bit);

    map<int, ll> acc_p;
    map<int, ll> acc_m;
    {
        acc_p[0] = 1;
        acc_m[1] = 2;
        for (int i = 2; i <= high_bit; i++) {
            ll diff = 1LL << i;
            if (i % 2 == 0) {
                acc_p[i] = diff;
                acc_p[i] += acc_p[i - 2];
            } else {
                acc_m[i] = diff;
                acc_m[i] += acc_m[i - 2];
            }
        }
    }

    // printf("acc_p: ");
    // for (auto &p : acc_p) {
    //     cout << p.second << " ";
    // }
    // cout << endl;
    // printf("acc_m: ");
    // for (auto &m : acc_m) {
    //     cout << m.second << " ";
    // }
    // cout << endl;

    ll acc = N;
    vector<int> bits;
    for (int bit = high_bit; bit >= 0; bit--) {
        // printf("acc: %d\n", acc);

        if (bit % 2 == 0) {
            if (acc >= 0 && abs(acc) <= acc_p[bit] && abs(acc) > acc_p[bit - 2]) {
                bits.push_back(1);
                acc -= pow(-2, bit);
                // printf("bit: %d, -= %d\n", bit, pow(-2, bit));
            } else {
                bits.push_back(0);
            }
        } else {
            if (acc < 0 && abs(acc) <= acc_m[bit] && abs(acc) > acc_m[bit - 2]) {
                bits.push_back(1);
                acc -= pow(-2, bit);
                // printf("bit: %d, -= %d\n", bit, pow(-2, bit));
            } else {
                bits.push_back(0);
            }
        }
    }

    // if (acc == 0) {
    //     bits.push_back(0);
    //     bits.push_back(0);
    // } else if (acc == 1) {
    //     bits.push_back(0);
    //     bits.push_back(1);
    // } else if (acc == -2) {
    //     bits.push_back(1);
    //     bits.push_back(0);
    // } else if (acc == -1) {
    //     bits.push_back(1);
    //     bits.push_back(1);
    // } else {
    //     cerr << "invalid" << endl;
    //     return 1;
    // }

    for (int i = 0; i < (int) bits.size(); i++) {
        cout << bits[i];
    }
    cout << endl;

    return 0;
}
