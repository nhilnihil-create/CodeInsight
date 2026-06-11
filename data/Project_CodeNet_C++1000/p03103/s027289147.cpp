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
    int n, m;
    cin >> n >> m;

    struct Shop { large price, count; };
    auto shop = vector<Shop>(n);
    for (auto& i : shop)
        cin >> i.price >> i.count;
    sort(shop.begin(), shop.end(), [](auto&A , auto&B) {
        return (A.price < B.price) || (A.price == B.price && A.count > B.count);
    });
    
    auto have = 0LL;
    auto cost = 0LL;
    for (auto& s : shop) {
        auto want = m - have;
        auto amount = min(want, s.count);
        cost += amount * s.price;
        have += amount;
        if (have >= m) break;
    }

    cout << cost << endl;
    return 0;
}
