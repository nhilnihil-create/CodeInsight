#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int inf = 1e9;

template <typename T>
class fenwick_tree {
public:
    fenwick_tree(int n_) : n(n_), dat(n, 0) {}

    void add(int i, T value) {
        for(; i < n; i |= i + 1) {
            dat[i] += value;
        }
    }

    T sum(int i) const {
        T res = 0;
        for(; i >= 0; i = (i & (i + 1)) - 1) {
            res += dat[i];
        }
        return res;
    }
    T sum(int l, int r) const {
        return sum(r - 1) - sum(l - 1);
    }

private:
    const int n;
    std::vector<T> dat;
};

int main() {
    ll n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    const ll half = n * (n + 1) / 4 + 1;
    auto check = [&] (int x) {
        const int offset = n + 1;
        fenwick_tree<ll> bit(2 * n + 2);
        bit.add(offset, 1);
        ll sum = 0, cnt = 0;
        for(int i = 0; i < n; ++i) {
            sum += (a[i] <= x ? 1 : -1);
            cnt += bit.sum(sum + offset - 1);
            bit.add(sum + offset, 1);
        }
        return cnt >= half;
    };
    int lb = -1, ub = inf + 1;
    while(ub - lb > 1) {
        const int mid = (lb + ub) >> 1;
        (check(mid) ? ub : lb) = mid;
    }

    cout << ub << endl;
}