#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(long long)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

template<class T> void vin(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

template<typename T>
struct BIT {
    vector<T> array;
    int n;

    BIT(int n) : array(n+1, 0), n(n) {}

    void init() {
        rep(i, n) array[i] = 0;
    }

    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += array[i];
            i -= i&-i;
        }
        return s;
    }

    T sum(int l, int r) {
        T ls = sum(l-1);
        T rs = sum(r);
        return rs - ls;
    }

    void add(int i, T x) {
        while (i <= n) {
            array[i] += x;
            i += i&-i;
        }
    }

};

int offset = 100000;
int N, A[101010];
BIT<int> bit(201010);

int check(int x) {
    bit.init();

    ll sm = 0;
    int tot = 0;
    bit.add(offset, 1);
    rep(i, N) {
        if (x <= A[i]) tot++;
        else tot--;

        sm += bit.sum(1, tot+offset);
        bit.add(tot+offset, 1);
    }

    return (1LL * N * (N-1) / 2 + N + 1) / 2 <= sm;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    int ng = 0, ok = 1e9+1;
    rep(i, N) {
        cin >> A[i];
        ng = max(ng, A[i]);
        ok = min(ok, A[i]);
    }

    ok--; ng++;
    while (ok+1 != ng) {
        int md = (ng + ok) / 2;
        if (check(md)) ok = md;
        else ng = md;
    }

    cout << ok << endl;
}
