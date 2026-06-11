#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    if (d == 0)
    {
        cout << setprecision(12) << static_cast<double>(m - 1) / static_cast<double>(n) << endl;
    }
    else
    {
        cout << setprecision(12) << static_cast<double>(m - 1) * 2.0 * static_cast<double>(n - d)
            / static_cast<double>(n) / static_cast<double>(n) << endl;
    }
}
