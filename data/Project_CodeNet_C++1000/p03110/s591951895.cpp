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
    int n;
    cin >> n;

auto sum = 0LL;
    for (int i = 0; i < n; ++i) {
        string x;
        double u;
        cin >> u >> x;
        if (x == "JPY") {
            sum += large(round(u * 1e8));
        }
        if (x == "BTC") {
           sum += large(round(u * 380'000 * 1e8));
        }
    }

    auto whole = sum / 100'000'000LL;
    auto fract = sum % 100'000'000LL;
    printf("%lld.%08lld\n", whole, fract);

    return 0;
}
