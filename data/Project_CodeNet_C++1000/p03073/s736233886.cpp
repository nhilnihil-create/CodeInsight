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
    string s;
    cin >> s;

    const auto n = int(s.length());
    auto cnt = 0;
    for (auto i = 0; i < n; ++i) {
        if (s[i] == i % 2 + '0')
            ++cnt;
    }
    cout << min(cnt, n - cnt) << endl;
    return 0;
}
