#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{
    string s;
    cin >> s;

    string make = "AKIHABARA";

    int midx = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (midx == make.size())
        {
            printf("NO\n");
            return 0;
        }

        if (s[i] != make[midx])
        {
            if (make[midx] != 'A')
            {
                printf("NO\n");
                return 0;
            }
            midx++;

            if (midx == make.size() || s[i] != make[midx])
            {
                printf("NO\n");
                return 0;
            }
        }

        midx++;
    }

    if (midx >= make.size() - 1)
        printf("YES\n");
    else
        printf("NO\n");


    return 0;
}