#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

// using mint = modint1000000007;
// using mint = modint998244353;

typedef int64_t Int;
#define all(x) (x).begin(), (x).end()
 
const double EPS = 1e-10;
const Int INF = 1e18;
const int inf = 1e9;
const Int mod = 1e9+7;

bool print_space_enable = false;
void print() { 
    cout << '\n'; 
    print_space_enable = false;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    if (print_space_enable) std::cout << " ";
    cout << fixed << setprecision(15) << head;
    print_space_enable = true;
    print(std::forward<Tail>(tail)...);
}

template<typename T>
void print(vector<T> v) {
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0) std::cout << " ";
        std::cout << v[i];
    }
    std::cout << '\n';
}

void solve() {
    Int a, b, q;
    cin >> a >> b >> q;
    vector<Int> s(a + 1), t(b + 1), x(q);
    for (Int i = 0; i < a; i++) {
        cin >> s[i + 1];
    }
    s[0] = -INF;
    s.push_back(INF);
    for (Int i = 0; i < b; i++) {
        cin >> t[i + 1];
    }
    t[0] = -INF;
    t.push_back(INF);
    for (Int i = 0; i < q; i++) {
        cin >> x[i];
    }
    for (Int i = 0; i < q; i++) {
        Int sr = *lower_bound(all(s), x[i]) - x[i];
        Int tr = *lower_bound(all(t), x[i]) - x[i];
        Int sl = x[i] - *(--lower_bound(all(s), x[i]));
        Int tl = x[i] - *(--lower_bound(all(t), x[i]));
        print(min({max(sr, tr), max(sl, tl), min(sr, tl) * 2 + max(sr, tl), min(sl, tr) * 2 + max(sl, tr)}));
    }
}

int main() {
    solve();
    return 0;
}
