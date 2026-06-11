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

ll calc(ll a) {
    ll x = (a + 1) / 2;
    if (a % 2 == 0) {
        return a ^ (x % 2);
    } else {
        return x % 2;
    }
}

int main(void) {
    ll A, B;
    cin >> A >> B;

    ll a = calc(A - 1);
    ll b = calc(B);
    cout << (b ^ a) << endl;

    return 0;
}
