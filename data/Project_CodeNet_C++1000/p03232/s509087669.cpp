#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

constexpr std::int64_t MOD = 1000000007LL;

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    std::int64_t N;
    std::cin >> N;
    std::vector<std::int64_t> cost(N);
    for (auto& c : cost) {
        std::cin >> c;
    }
    if (N == 1) {
        std::cout << cost[0] % MOD << std::endl;
        return 0;
    }
    if (N == 2) {
        std::cout << (cost[0] + cost[1]) * 3 % MOD << std::endl;
        return 0;
    }
    {
        std::vector<std::int64_t> facto1(N);
        std::vector<std::int64_t> facto2(N + 1);
        std::vector<std::int64_t> coef(N);
        std::vector<std::int64_t> coef2(N);
        {
            facto1[0] = 1;
            for (std::int64_t i = 1; i < N; ++i) {
                facto1[i] = facto1[i - 1] * (i + 1) % MOD;
            }
            facto2[N] = 1;
            facto2[N - 1] = N;
            for (std::int64_t i = N - 2; i >= 0; --i) {
                facto2[i] = facto2[i + 1] * (i + 1) % MOD;
            }
            coef[0] = facto1[N - 1];
            coef2[0] = facto1[N - 1];
            coef[1] = facto1[N - 2];
            coef2[1] = facto1[N - 2];
            for (std::int64_t i = 2; i < N; ++i) {
                coef[i] = (facto1[N - i - 1] * facto2[N - i + 2] * 2) % MOD;
                coef2[i] = (facto1[N - i - 1] * facto2[N - i + 1]) % MOD;
            }
        }
        std::int64_t left = (N - 1) / 2;
        std::int64_t right = N / 2;
        std::int64_t sum_num = 0;
        std::int64_t sum_coef = 0;
        std::int64_t sum_cost = 0;
        if (left == right) {
            sum_num = cost[left];
            sum_coef = coef[left];
            sum_cost = sum_num * sum_coef % MOD;
        } else {
            sum_num = cost[left] + cost[right];
            sum_coef = coef[left] + coef[right];
            sum_cost = sum_num * sum_coef % MOD;
        }
        while (true) {
            if (left == 0) {
                break;
            }
            --left;
            ++right;
            sum_num = (sum_num + cost[left] + cost[right]) % MOD;
            sum_coef = (sum_coef + coef[left] + coef[right]) % MOD;
            sum_cost = (sum_cost + sum_num * sum_coef) % MOD;
        }
        {
            std::int64_t temp_sum = 0;
            for (std::int64_t i = 0; i < N - 2; ++i) {
                temp_sum = (temp_sum + cost[i]) % MOD;
                sum_cost = (sum_cost - temp_sum * coef[N - i - 1] + temp_sum * coef2[N - i - 1] + MOD * temp_sum) % MOD;
            }
        }
        {
            std::int64_t temp_sum = 0;
            for (std::int64_t i = N - 1; i > 1; --i) {
                temp_sum = (temp_sum + cost[i]) % MOD;
                sum_cost = (sum_cost - temp_sum * coef[i] + temp_sum * coef2[i] + MOD * temp_sum) % MOD;
            }
        }
        std::cout << sum_cost % (MOD) << std::endl;
    }
    return 0;
}
