#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
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
    int k;
    cin >> k;

    int n = 2;
    int ans = 0;
    while (n <= k)
    {
        int odd = 1;
        while (odd <= k)
        {
            ans++;
            odd += 2;
        }
        n += 2;
    }
    cout << ans;
}