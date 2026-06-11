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
const auto red = '0';
const auto blue = '1';

int main()
{
    string s;
    cin >> s;
    const int n = int(s.length());
    int cnt = 0;

    string skipped;
    skipped.reserve(n);
    skipped.push_back('*');

    for (int i = 0; i < n; ++i) {
        auto t = s[i] == '0' ? '1' : '0';
        if (skipped.back() == t) {
            skipped.pop_back();
            cnt += 2;
            continue;
        }
        skipped.push_back(s[i]);
    }

    cout << cnt << endl;
    return 0;
}
