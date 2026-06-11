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
    large m, k;
    cin >> m >> k;

    if (m == 0) {
        if (k == 0) {
            printf("0 0\n");
            return 0;
        }
        printf("-1\n");
        return 0;
    }

    if (m == 1) {
        if (k == 0) {
            printf("0 0 1 1\n");
            return 0;
        }
        printf("-1\n");
        return 0;
    }

    auto Mx = (1LL << m) - 1;
    if (k > Mx) {
        printf("-1\n");
        return 0;
    }

    for (auto i = 0LL; i <= Mx; ++i)
        if (i != k)
            printf("%lld ", i);

    printf("%lld ", k);

    for (auto i = Mx; i >= 0; --i)
        if (i != k)
            printf("%lld ", i);

    printf("%lld\n", k);
    return 0;
}
