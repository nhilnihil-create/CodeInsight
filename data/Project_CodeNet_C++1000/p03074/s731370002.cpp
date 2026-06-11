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
#include <set>
#include <deque>
#include <numeric>
using lint = long long;

int main()
{
    lint n, k;
    scanf("%lld", &n);
    scanf("%lld", &k);

    std::string s;
    std::cin >> s;

    std::vector<lint> line;
    std::vector<lint> line_state;

    lint stream = 0;
    lint state;

    if (s.front() == '0')
        state = 0;
    else
        state = 1;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            if (state == 0)
            {
                stream++;
            }
            else
            {
                line.push_back(stream);
                line_state.push_back(state);
                stream = 1;
                state = 0;
            }
        }
        else
        {
            if (state == 1)
            {
                stream++;
            }
            else
            {
                line.push_back(stream);
                line_state.push_back(state);
                stream = 1;
                state = 1;
            }
        }
    }
    line.push_back(stream);
    line_state.push_back(state);

    if (line_state.size() - std::accumulate(line_state.begin(), line_state.end(), 0) <= k)
    {
        printf("%lld", n);
        return 0;
    }
    else
    {
        std::vector<lint> line_cumsum(line.size());
        lint cumsum = 0;
        for (lint i = 0; i < line.size(); i++)
        {
            cumsum += line[i];
            line_cumsum[i] = cumsum;
        }

        lint ans = 0;
        lint cand;

        for (int i = 0; i < line.size(); i++)
        {
            lint right;
            lint left;
            if (line_state[i] == 0)
            {
                left = std::max(0, i - 1);
                right = std::min(i + 2 * int(k) - 1, int(line.size()) - 1);
            }
            else
            {
                left = i;
                right = std::min(i + 2 * int(k), int(line.size()) - 1);
            }

            if (right >= line.size())
                break;
            if (left == 0)
                cand = line_cumsum[right];
            else
                cand = line_cumsum[right] - line_cumsum[left - 1];
            ans = std::max(ans, cand);
        }
        printf("%lld", ans);
        return 0;
    }
    return 0;
}
