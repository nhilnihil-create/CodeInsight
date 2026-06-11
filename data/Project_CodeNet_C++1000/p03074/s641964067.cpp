#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <climits>
#include <cstdint>
#include <string>
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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vec<int> zsum;
    for (int i = 0; i < s.size();) {
        bool found = false;
        while (i < s.size() && s[i] == '1') ++i;
        while (i < s.size() && s[i] == '0') {
            found = true;
            ++i;
        }
        while (i < s.size() && s[i] == '1') ++i;
        if (!found) continue;
        zsum.push_back(i);
    }

    if (zsum.size() == 0) {
        cout << s.size() << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 0, cnt = 0; i < s.size(); ++cnt) {
        ans = max(ans, zsum[min((size_t)(cnt + k), zsum.size()) - 1] - i);

        while (i < s.size() && s[i] == '1') ++i;
        while (i < s.size() && s[i] == '0') ++i;
    }

    cout << ans << endl;
}

