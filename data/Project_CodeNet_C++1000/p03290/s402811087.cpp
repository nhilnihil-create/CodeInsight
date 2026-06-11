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
    Int n, x;
    cin >> n >> x;
    vector<Int> p(n), c(n);
    for (Int i = 0; i < n; i++) {
        cin >> p[i] >> c[i];
    }
    Int res = INF;
    for (Int bit = 0; bit < (1<<n); bit++) {
        Int s = 0;
        Int cnt = 0;
        for (Int i = 0; i < n; i++) {
            if (bit & (1<<i)) {
                s += c[i];
                s += 100 * (i + 1) * p[i];
                cnt += p[i];
            }
        }
        vector<Int> b;
        for (Int i = 0; i < n; i++) {
            if (bit & (1<<i)) continue;
            for (Int j = 0; j < p[i]; j++) {
                b.push_back(100 * (i + 1));
            }
        }
        sort(all(b), greater<Int>());
        if (s >= x) {
            res = min(cnt, res);
            continue;
        }
        for (Int i = 0; i < (Int)b.size(); i++) {
            s += b[i];
            cnt++;
            if (s >= x) {
                res = min(res, cnt);
                break;
            }
        }
    }
    print(res);
}

int main() {
    solve();
    return 0;
}
