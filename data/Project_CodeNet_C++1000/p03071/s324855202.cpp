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
    int a, b;
    cin >> a >> b;

    int sum = 0;
    if (a >= b)
    {
        sum += a--;
    } else sum += b--;
    if (a >= b)
        sum += a--;
    else sum += b--;
    cout << sum;
}