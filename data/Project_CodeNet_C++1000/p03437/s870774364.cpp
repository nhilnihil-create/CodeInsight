#include <iostream>
#include <cstdint>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <sstream>

int main(void)
{
    int64_t X, Y;
    std::cin >> X >> Y;

    if (X % Y == 0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    int64_t i = 1;
    int64_t ans = 0;
    while (true) {
        i++;
        ans = X * i;
        if (ans % Y != 0) break;
    }

    std::cout << ans << std::endl;

    return 0;
}
