#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

template <typename T>
vector<T> _divisor(T a) {
    vector<T> res;
    for (T i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            res.push_back(i);
            if (i != 1 && i * i != a)
                res.push_back(a / i);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    vll a = _divisor(n);
    a.push_back(n);

    ll cnt = 0;
    rep(i, a.size()) {
        if (a[i] > sqrt(n)+1) {
            cnt += a[i] - 1;
        }
    }

    cout << cnt << endl;
}