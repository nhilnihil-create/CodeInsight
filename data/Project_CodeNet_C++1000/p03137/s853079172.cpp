#include <bits/stdc++.h>
using namespace std;

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
    Int n, m;
    cin >> n >> m;
    vector<Int> a(m);
    for (Int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(all(a), greater<Int>());
    vector<Int> b(m - 1);
    for (Int i = 0; i < m - 1; i++) {
        b[i] = a[i] - a[i + 1];
    }
    Int sum = accumulate(all(b), (Int)0);
    sort(all(b), greater<Int>());
    for (Int i = 0; i < min(n - 1, m - 1); i++) {
        sum -= b[i];
    }
    print(sum);
}

int main() {
    solve();
    return 0;
}
