#include <bits/stdc++.h>
using namespace std;


template<typename T>
vector<T> fast_zeta_transform(const vector<T>& f) {
    int n = f.size();
    vector<T> g = f;
    for (int i = 0; (1 << i) < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j >> i & 1) {
                g[j] += g[j & ~(1<<i)];
            }
        }
    }
    return g;
}

struct Pair {
    int a, b;
    Pair& operator+=(const Pair &p) {
        vector<int> v{ a, b, p.a, p.b };
        sort(v.rbegin(), v.rend());
        a = v[0], b = v[1];
        return *this;
    }
};


int main()
{
    int n; cin >> n;
    vector<int> a(1<<n);
    for (int i = 0; i < 1<<n; ++i) {
        cin >> a[i];
    }

    vector<Pair> f(1<<n);
    for (int i = 0; i < 1<<n; ++i) {
        f[i] = { a[i], 0 };
    }

    vector<Pair> g = fast_zeta_transform(f);

    int ans = 0;
    for (int i = 1; i < 1<<n; ++i) {
        ans = max(ans, g[i].a + g[i].b);
        cout << ans << endl;
    }

    return 0;
}
