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
    int64_t n, h, w;
    cin >> n >> h >> w;

    int64_t count = 0;
    for (int i = 0; i < n; i++)
    {
        int64_t a, b;
        cin >> a >> b;
        count += (h <= a && w <= b ? 1 : 0);
    }
    cout << count << endl;
}
