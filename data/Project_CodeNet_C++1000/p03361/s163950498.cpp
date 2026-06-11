#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int H, W; cin >> H >> W;
    vector<vector<int>> grids(H + 2, vector<int>(W + 2, 0));
    for (int r = 1; r <= H; ++r)
    {
        string row; cin >> row;
        for (int c = 1; c <= W; ++c)
        {
            grids[r][c] = row[c - 1] == '#' ? 1 : 0;
        }
    }
    bool isOK = true;
    for (int r = 1; r <= H; ++r)
    {
        for (int c = 1; c <= W; ++c)
        {
            if (grids[r][c] == 1)
            {
                if (grids[r - 1][c] == 0 && grids[r + 1][c] == 0
                    && grids[r][c - 1] == 0 && grids[r][c + 1] == 0)
                {
                    isOK = false;
                }
            }
        }
    }
    cout << (isOK ? "Yes\n" : "No\n");
}