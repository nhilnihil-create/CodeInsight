#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <climits>
#include <cstdint>
#include <map>
using namespace std;

inline namespace atcoder {
    template <typename T, size_t Depth>
    struct vector_helper { using type = vector<typename vector_helper<T, Depth - 1>::type>; };
    template <typename T>
    struct vector_helper<T, 0> { using type = T; };
    template <typename T, size_t Depth>
    using vector_t = typename vector_helper<T, Depth>::type;

    template <typename T> using vec = vector_t<T, 1>;
    template <typename T> using vvec = vector_t<T, 2>;
    template <typename T> using vvvec = vector_t<T, 3>;
}

int main() {
    int n; cin >> n;
    map<int, int> problems;
    while (n--) {
        int a; cin >> a;
        ++problems[a];
    }
    int m; cin >> m;
    while (m--) {
        int a; cin >> a;
        auto find = problems.find(a);
        if (find == problems.end() || find->second-- == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}

