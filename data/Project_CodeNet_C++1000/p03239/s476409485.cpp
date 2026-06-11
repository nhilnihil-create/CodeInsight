#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
#include <iomanip>
#include <numeric>
#include <climits>
#include <algorithm>
#include <cstdint>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int ci, ti;
        cin >> ci >> ti;

        if (ti <= t)
        {
            if (ci < min)
                min = ci;
        }
    }
    min == INT_MAX ? cout << "TLE" : cout << min;
}