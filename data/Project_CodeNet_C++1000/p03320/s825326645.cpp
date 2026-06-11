#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll calc(ll x) {
    ll res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    /*
    ll x1 = 0, s1 = 0;
    deque<ll> v;
    for (ll i = 10000000000000000LL; i >= 1; i--) {
        ll sum = calc(i);
        if (x1 * sum >= i * s1) {
            x1 = i;
            s1 = sum;
            v.push_front(i);
        }
    }
    cout << v.size() << endl;
    for (ll x : v) {
        cout << x << endl;
    }*/

    vector<ll> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int lim = 1000;
    int plus = 10;
    ll d = 10;
    while (d <= 1000000000000000LL) {
        for (int i = 1; i < lim; i++) {
            v.push_back(i * d + (d - 1));
            if (v.back() > 1000000000000000LL) {
                v.pop_back();
                break;
            }
        }
        d *= 10;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    reverse(v.begin(), v.end());

    ll x1 = 0, s1 = 0;
    deque<ll> dq;
    for (ll i : v) {
        ll sum = calc(i);
        if (x1 * sum >= i * s1) {
            x1 = i;
            s1 = sum;
            dq.push_front(i);
        }
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        cout << dq[i] << endl;
    }
    return 0;
}