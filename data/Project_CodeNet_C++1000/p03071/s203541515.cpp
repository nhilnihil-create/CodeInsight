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
    int a, b;
    cin >> a >> b;

    cout << (a == b ? 2 * a : max(a, b) + max(a, b) - 1) << endl;
    return 0;
}
