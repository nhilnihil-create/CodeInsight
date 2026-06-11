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
    vector<Int> b(n);
    for (Int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<Int> c = b;
    sort(all(b));
    vector<pair<Int, Int>> a(n);
    for (Int i = 0; i < n; i++) {
        a[i] = {b[i], i};
    }
    map<Int, Int> mp;
    for (Int i = 0; i < n; i++) {
        if (a[i].second < n / 2) {
            mp[a[i].first] = b[n / 2];
        } else {
            mp[a[i].first] = b[n / 2 - 1];
        }
    }
    for (Int i = 0; i < n; i++) {
        print(mp[c[i]]);
    }
}

int main() {
    solve();
    return 0;
}
