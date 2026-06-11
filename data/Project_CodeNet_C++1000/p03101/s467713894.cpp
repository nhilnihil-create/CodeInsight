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
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    auto cells = H * W;
    cells -= w * H;
    cells -= h * W;
    cells += w * h;

    cout << cells << endl;
    return 0;
}