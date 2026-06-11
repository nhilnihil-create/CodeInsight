#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <sstream>
#include <iomanip>
using lint = long long;

int main()
{
    lint n;
    scanf("%lld", &n);

    lint l = 0;
    std::cout << l << "\n";
    std::string sl;
    std::string sr;
    std::cin >> sl;
    sr = sl;

    if (sl == "Vacant")
        return 0;

    lint r = n;
    lint c = (l + r) / 2;
    std::cout << c << "\n";
    std::string sc;
    std::cin >> sc;

    if (sc == "Vacant")
        return 0;

    for (int i = 0; i < 18; ++i)
    {
        if ((c - l) % 2 != 0)
        {
            if (sl == sc)
            {
                r = c;
                sr = sc;
                c = (r + l) / 2;
            }
            else
            {
                l = c;
                sl = sc;
                c = (r + l) / 2;
            }
        }
        else if ((c - l) % 2 == 0)
        {
            if (sl != sc)
            {
                r = c;
                sr = sc;
                c = (r + l) / 2;
            }
            else
            {
                l = c;
                sl = sc;
                c = (r + l) / 2;
            }
        }

        std::cout << c << "\n";

        std::cin >> sc;
        if (sc == "Vacant")
            return 0;
    }
    return 0;
}
