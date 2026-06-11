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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    auto len = vector<int>();
    auto i = 0;
    while (s[i] == '1')
        ++i;
    const auto offset = i;

    while (i < n) {
        auto i0 = i;
        for (++i; i<n && s[i] == s[i0]; ++i)
            (void)0;
        len.push_back(i - i0);
    }

    auto sum = vector<int>(len.size() + 1);
    sum[0] = 0;
    for (i = 0; i < len.size(); ++i)
        sum[i + 1] = sum[i] + len[i];

    auto cnt_max = offset;

    for (i = 0; i < len.size(); i += 2) {
        auto j = i + 2 * k - 1;
        if (j > len.size() - 1)
            j = len.size() - 1;

        auto cnt = sum[j + 1] - sum[i];

        if (i == 0)
            cnt += offset;
        else
            cnt += len[i - 1];

        if (j % 2 == 0 && j + 1 < len.size())
            cnt += len[j + 1];

        cnt_max = max(cnt_max, cnt);
    }

    cout << cnt_max << endl;
    return 0;
}
