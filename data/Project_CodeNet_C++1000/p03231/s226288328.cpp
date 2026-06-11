#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int64_t gcd(int64_t a, int64_t b)
{
    if (a < b)
    {
        return gcd(b, a);
    }
    else if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int64_t lcm(int64_t a, int64_t b) { return a * b / gcd(a, b); }

int main()
{
    int64_t n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    const auto g = gcd(n, m);

    bool success = true;
    for (int i = 0; i < g; i++)
    {
        if (s[n * i / g] != t[m * i / g])
        {
            success = false;
        }
    }
    cout << (success ? lcm(n, m) : -1) << endl;
}
