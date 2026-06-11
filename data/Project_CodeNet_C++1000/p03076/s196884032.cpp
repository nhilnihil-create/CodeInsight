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

int main()
{
    int t[5];
    for (auto& ti : t)
        cin >> ti;

    auto total = 0;
    for (auto ti : t)
        total += (ti + 9) / 10 * 10;
    auto mx = 0;
    for (auto ti : t) {
        auto rem = (10 - ti % 10) % 10;
        mx = max(mx, rem);
    }
    cout << (total - mx) << endl;
    return 0;
}
