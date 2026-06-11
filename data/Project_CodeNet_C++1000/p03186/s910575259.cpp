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
    int64_t a, b, c;
    cin >> a >> b >> c;

    int poison = min(c, a + b + 1);
    cout << (b + poison) << endl;
}
