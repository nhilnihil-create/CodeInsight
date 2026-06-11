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
    int N; cin >> N;
    vector<LLONG> sums(N + 1, 0LL);
    LLONG sum = 0;
    for (int i = 0; i < N; ++i)
    {
        LLONG ai; cin >> ai;
        sums[i + 1] = sums[i] + ai;
    }
    map<LLONG, LLONG> sum2NumMap;
    for (int i = 0; i <= N; ++i)
    {
        ++sum2NumMap[sums[i]];
    }
    LLONG ans = 0;
    for (const auto &kvp : sum2NumMap)
    {
        LLONG num = kvp.second;
        ans += num * (num - 1) / 2;
    }
    cout << ans << endl;
}