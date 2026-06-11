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
    string s;
    cin >> s;

    int maxlen = 0;
    for (auto i = 0; i < s.length(); ++i) {
        for (auto j = i + 1; j <= s.length(); ++j) {
            auto t = s.substr(i, j - i);
            auto pos = t.find_first_not_of("ACGT");
            if (pos < t.length())
                continue;
            maxlen = max(maxlen, j - i);
        }
    }
    

    cout << maxlen << endl;
    return 0;
}
