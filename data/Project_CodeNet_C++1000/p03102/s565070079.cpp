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
    int n, m, c;
    cin >> n >> m >> c;

    auto b = vector<int>(m);
    auto a = vector<vector<int>>(n, vector<int>(m));
    for (auto& b_i : b)
        cin >> b_i;
    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    auto cnt = 0;
    for (auto i = 0; i < n; ++i) {
        auto sum = 0LL;
        for (auto x = 0; x < m; ++x) {
            sum += a[i][x] * b[x];
        }
        sum += c;
        if (sum > 0)
            cnt++;
    }

    cout << cnt << endl;
    return 0;
}
