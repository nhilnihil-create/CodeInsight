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
    std::string s;
    std::cin >> s;

    lint len = s.size();

    lint left = 0;
    lint right = len - 1;

    lint ans = 0;
    lint ng = 0;

    while (left < right)
    {
        char sl = s[left];
        char sr = s[right];
        if (sl == sr)
        {
            left++;
            right--;
        }
        else if (sl == 'x')
        {
            left++;
            ans++;
        }
        else if (sr == 'x')
        {
            right--;
            ans++;
        }
        else
        {
            ng = 1;
            break;
        }
    }

    if (ng)
        printf("-1");
    else
        printf("%lld", ans);

    return 0;
}
