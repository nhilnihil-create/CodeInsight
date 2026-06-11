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

std::vector<int64_t> get_divisor(int64_t n)
{
    std::vector<int64_t> ret;
    for (int64_t i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i != n / i)
            {
                ret.push_back(n / i);
            }
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main()
{
    int64_t n;
    cin >> n;

    int64_t sum = 0;

    auto divisors = get_divisor(n);

    for (auto div : divisors)
    {
        const auto m = n / div - 1;
        // m * div + div = n if (n % div == 0)
        if (m > div)
        {
            sum += m;
        }
        cerr << m << endl;
    }
    cout << sum << endl;
}
