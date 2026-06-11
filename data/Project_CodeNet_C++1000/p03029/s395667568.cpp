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
    int a, p;
    cin >> a >> p;

    p += a*3;
    int cnt = 0;
    while (p > 1)
    {
        cnt++;
        p -= 2;
    }
    cout << cnt;
}