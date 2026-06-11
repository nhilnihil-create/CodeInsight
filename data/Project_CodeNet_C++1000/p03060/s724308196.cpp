#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#undef min
#undef max
#else
#define NDEBUG
#include <bits/stdc++.h>
#endif

using namespace std;
using large = long long;

int main() {
    int n;
    cin >> n;

    auto v = vector<int>(n);
    auto c = vector<int>(n);
    for (auto& vi : v)
        cin >> vi;
    for (auto& ci : c)
        cin >> ci;

    auto sum = 0LL;
    for (auto i = 0; i < n; ++i)
        sum += max(0, v[i] - c[i]);

    cout << sum << "\n";
    return 0;
}
