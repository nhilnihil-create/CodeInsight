#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
T gcd(T a, T b) {
    if (a < b) {
        swap(a, b);
    }

    T r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

template <class T>
T lcm(const T& a, const T& b) {
    return (a * b) / gcd<T>(a, b);
}

const int INF = 1e9;
const long long LINF = 1e18;

int main() {
    long long X, Y;
    cin >> X >> Y;

    long long ans = 0;
    long long n1 = 1;
    long long n2 = X;
    while (n2 <= Y) {
        n2 = n2 * 2;
        ans++;
    }

    cout << ans << endl;
    return 0;
}
