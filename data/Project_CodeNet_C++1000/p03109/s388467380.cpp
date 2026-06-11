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
    int y, m, d;
    char c;
    cin >> y >> c >> m >> c >> d;

    int r = y - 2019;
    if (!r) {
        r = m - 4;
    }
    if (!r) {
        r = d - 30;
    }


    cout << (r <= 0 ? "Heisei" : "TBD") << endl;
    return 0;
}
