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
    string s;
    cin >> n >> k >> s;
    --k;

    s[k] = tolower(s[k]);

    cout << s;
    return 0;
}
