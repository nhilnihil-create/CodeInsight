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
    int a, b, k;
    cin >> a >> b >> k;

    int n = min(a, b);
    while (1)
    {
        if (a % n == 0 && b % n == 0)
            k--;
        if (k == 0)
        {
            cout << n;
            break;
        }
        n--;
    }
}