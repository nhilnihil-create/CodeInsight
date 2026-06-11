#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <regex>
#include <iomanip>
#include <climits>
#include <utility>
#include <queue>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

ll fact(ll n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return n * fact(n - 1) % MOD;
}

int main()
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout
        << (x2 + y1 - y2) << " " << (y2 + (x2 - x1)) << " "
        << (x1 + y1 - y2) << " " << (y1 + (x2 - x1)) << endl;
}