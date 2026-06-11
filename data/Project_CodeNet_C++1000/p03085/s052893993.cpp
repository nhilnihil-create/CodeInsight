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
    char table[256] = {};
    table['A'] = 'T';
    table['T'] = 'A';
    table['C'] = 'G';
    table['G'] = 'C';
    char b[2] = {};
    cin >> b[0];
    b[0] = table[b[0]];
    cout << b << endl;
    return 0;
}
