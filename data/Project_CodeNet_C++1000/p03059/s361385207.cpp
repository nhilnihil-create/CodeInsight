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
    int a, b, t;
    cin >> a >> b >> t;

    int now = 0;
    for (int i = 1; i <= t; i++)
        if (i % a == 0)
            now += b;
    cout << now;
}