#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int64_t x, y;
    cin >> x >> y;

    if (x % y == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << (x * (y - 1)) << endl;
    }
    return 0;
}
