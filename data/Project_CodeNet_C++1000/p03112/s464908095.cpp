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
    int a, b, q;
    cin >> a >> b >> q;
    auto s = set<large>{};
    s.insert(-1e18);
    s.insert(1e18);
    auto s_inv = s;
    for (int i = 0; i < a; ++i) {
        large s_i;
        cin >> s_i;
        s.insert(s_i);
        s_inv.insert(-s_i);
    }

    auto t = set<large>{};
    t.insert(-1e18);
    t.insert(1e18);
    auto t_inv = t;
    for (int i = 0; i < b; ++i) {
        large t_i;
        cin >> t_i;
        t.insert(t_i);
        t_inv.insert(-t_i);
    }

    for (int i = 0; i < q; ++i) {
        large x;
        cin >> x;

        auto s_right = *s.lower_bound(x);
        auto s_left = -*s_inv.lower_bound(-x);

        auto t_right = *t.lower_bound(x);
        auto t_left = -*t_inv.lower_bound(-x);

        s_right = s_right - x;
        s_left = x - s_left;
        t_right = t_right - x;
        t_left = x - t_left;

        auto dist = min({
            2 * s_right + t_left,
            2 * s_left + t_right,
            2 * t_right + s_left,
            2 * t_left + s_right,

            max(s_right, t_right),
            max(s_left, t_left),
        });

        cout << dist << "\n";
    }

    return 0;
}
