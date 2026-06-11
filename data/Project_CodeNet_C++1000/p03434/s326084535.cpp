#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <climits>
#include <cstdint>
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
    vec<int> cards(n);
    for (auto &e : cards) cin >> e;
    sort(cards.rbegin(), cards.rend());

    int alice = 0, bob = 0;
    for (int i = 0; i < n; i += 2) alice += cards[i];
    for (int i = 1; i < n; i += 2) bob += cards[i];

    cout << alice - bob << endl;
}

