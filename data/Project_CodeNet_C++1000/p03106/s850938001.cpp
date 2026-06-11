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
    int a, b, k;
    cin >> a >> b >> k;
    int d = 110;
    while (k--) {
        --d;
        while (a % d || b % d)
            --d;
    }

    cout << d << endl;
    return 0;
}
