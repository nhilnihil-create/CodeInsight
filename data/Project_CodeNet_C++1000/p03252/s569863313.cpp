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

    std::string t;
    std::cin >> t;

    std::map<char, std::unordered_set<char>> smap;
    std::map<char, std::unordered_set<char>> tmap;

    for (int i = 0; i < s.size(); ++i)
    {
        char s_char = s[i];
        char t_char = t[i];

        smap[s_char].insert(t_char);
        tmap[t_char].insert(s_char);

        if (smap[s_char].size() > 1 || tmap[t_char].size() > 1)
        {
            printf("No");
            return 0;
        }
    }

    printf("Yes");

    return 0;
}
