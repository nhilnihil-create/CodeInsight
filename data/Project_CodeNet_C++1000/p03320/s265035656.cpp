#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

ll S(ll n) {
    ll result = 0;
    while (n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

double f(ll n) {
    return (double)n / S(n);
}

int main() {
    ll K;
    cin >> K;

    vector<ll> candidates;

    for (ll i = 0; i < 15; i++) {
        //下からi桁目まで9が続く
        for (ll j = 0; j < pow(10, 4); j++) {
            candidates.push_back(j * pow(10, i) + pow(10, i) - 1);
        }
    }

    sort(candidates.begin(), candidates.end(), [](ll &lhs, ll &rhs) {
        return f(lhs) < f(rhs);
    });

    ll u = 0, cnt = 0;
    for (auto e : candidates) {
        if (e > u) {
            cout << e << endl;
            u = e;
            if (++cnt == K) {
                break;
            }
        }
    }
}