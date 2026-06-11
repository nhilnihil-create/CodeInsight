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
    int a,b,c,d,e,k;
    cin >> a>>b>>c>>d>>e>>k;

    cout << (e-a <= k ? "Yay!" : ":(") << endl;
    return 0;
}
