#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

double Snuke(ll x) {
    ll tmp = 0, c = x;
    while(c) {
        tmp += c % 10;
        c /= 10;
    }
    return 1.0 * x / tmp;
}

int main() {
    int K;
    cin >> K;
    ll res = 0, x = 1;
    while(K--) {
        double t1, t2;
        while(true) {
            t1 = Snuke(res + x), t2 = Snuke(res + x * 10);
            if(t1 <= t2) break;
            x *= 10;
        }
        res += x;
        printf("%lld\n", res);
    }
    return 0;
}
