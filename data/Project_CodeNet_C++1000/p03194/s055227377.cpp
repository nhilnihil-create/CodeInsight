#include <cstdio>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <unordered_map>

std::unordered_map<uint64_t, uint64_t> makeFactors(uint64_t n)
{
    uint64_t val = n;
    std::unordered_map<uint64_t, uint64_t> factors;

    while (val % 2 == 0) {
        if (factors.count(2) == 0) {
            factors[2] = 1;
        } else {
            uint64_t cnt = factors[2];
            factors[2] = cnt + 1;
        }
        val /= 2;
    }

    if (val == 1) {
        return factors;
    }

    uint64_t divisor = 3;
    while (val != 1 && divisor <= val) {
        while (val % divisor == 0) {
            if (factors.count(divisor) == 0) {
                factors[divisor] = 1;
            } else {
                uint64_t cnt = factors[divisor];
                factors[divisor] = cnt + 1;
            }
            val /= divisor;
        }

        if (std::sqrt(val) <= divisor) {
            factors[val] = 1;
            break;
        }

        divisor += 2;
    }

    return factors;
}

int main()
{
    uint64_t N, P;
    std::cin >> N >> P;

    std::unordered_map<uint64_t, uint64_t> factors = makeFactors(P);

    uint64_t max = 1;
    auto itr = factors.begin();
    while (itr != factors.end()) {
        if (itr->second >= N) {
            max *= std::pow(itr->first, (itr->second / N));
        }

        ++itr;
    }

    std::cout << max << std::endl;

    return 0;
}