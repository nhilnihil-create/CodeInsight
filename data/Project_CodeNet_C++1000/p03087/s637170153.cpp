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
    int n, q; // 100'000
    string s;
    cin >> n >> q >> s;
    auto is_ac_at = vector<int>(n);
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == 'A' && s[i + 1] == 'C')
            is_ac_at[i] = 1;
    }
    auto acc = vector<int>(n + 1);
    acc[0] = 0;
    for (int i = 0; i < n; ++i) {
        acc[i + 1] = acc[i] + is_ac_at[i];
    }

    for (auto a : acc)
        cerr << a << " ";
    cerr << "\n";

    for (int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        auto cnt = acc[r] - acc[l];
        cout << cnt << "\n";
    }

    return 0;
}
