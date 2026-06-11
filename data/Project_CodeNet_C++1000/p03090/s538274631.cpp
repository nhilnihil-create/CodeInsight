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
    Int n;
    cin >> n;
    if (n % 2 == 0) {
        Int k = n / 2;
        print(k * (k - 1) / 2 * 4);
        for (Int i = 1; i <= n; i++) {
            for (Int j = i + 1; j <= n; j++) {
                if (j == n + 1 - i) continue;
                print(i, j);
            }
        }
    } else {
        Int k = n / 2;
        print(4 * k * (k - 1) / 2 + n - 1);
        for (Int i = 1; i <= n - 1; i++) {
            for (Int j = i + 1; j <= n - 1; j++) {
                if (j == n - i) continue;
                print(i, j);
            }
        }
        for (Int i = 1; i <= n - 1; i++) {
            print(i, n);
        }
    }
}

int main() {
    solve();
    return 0;
}
