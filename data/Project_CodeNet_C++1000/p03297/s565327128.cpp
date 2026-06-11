#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>
#include <cstdint>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 998244353;


long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    int t; cin >> t;
    rep(i, t) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        if (b > d) {
            cout << "No" << endl;
            continue;
        }
        if (a < b) {
            cout << "No" << endl;
            continue;
        }
        if (c+1 >= b) {
            cout << "Yes" << endl;
            continue;
        }
        ll p = (a - c - 1) / b;
        p++;
        a -= b * p;
        if (a < 0) {
            cout << "No" << endl;
            continue;
        }
        
        // c+1 ~ b-1 にきたらNo
        // 0~c ならd足す
        // 毎回 b引く
        // 現在a (次d足す)

        // 毎回bでmodをとるのと同じ。c+1 ~ b-1 になるとNo。
        d = d % b;
        // 任意の非負整数xについて(a + d * x) % b <= c ならYes、それ以外ならNo。
        ll g = GCD(b, d);
        p = (b-1 - (a % g)) / g;
        if (p * g + (a % g) <= c) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}


    