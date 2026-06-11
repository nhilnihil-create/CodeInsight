#include <bits/stdc++.h>
using namespace std;

typedef int64_t Int;
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
 
const double EPS = 1e-10;
const Int INF = 1e18;
const int inf = 1e9;
const Int mod = 1e9+7;

bool print_space_enable = false;
void print() { 
    cout << endl; 
    print_space_enable = false;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    if (print_space_enable) cout << " ";
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
    std::cout << std::endl;
}

int main() {
    Int n;
    cin >> n;
    vector<Int> a(n), b(n);
    for (Int i = 0; i < (Int)n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<tuple<Int, Int, Int>> v(n);
    for (Int i = 0; i < (Int)n; i++) {
        v[i] = make_tuple(a[i] + b[i], a[i], b[i]);
    }
    sort(all(v), greater<tuple<Int, Int, Int>>());
    Int res = 0;
    for (Int i = 0; i < (Int)n; i++) {
        if (i % 2 == 0) {
            res += get<1>(v[i]);
        } else {
            res -= get<2>(v[i]);
        }
    }
    print(res);
    return 0;
}