#if !defined(__clang__) && defined(__GNUC__)
#include <bits/stdc++.h>
#else
#include <cstdlib>
#include <climits>
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <complex>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <regex>
#endif //  !defined(__clang__) && defined(__GNUG__)
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/multi_array.hpp>
#include <boost/optional.hpp>
#include <boost/math/common_factor_rt.hpp>

constexpr int64_t DIV1097 = 1000000007LL;

using namespace std;

int main()
{
    std::string S;
    std::cin >> S;

    int64_t a, b, c;
    a = b = c = 0;
    for (size_t i = 0; i < S.size(); ++i) {
        switch (S[i]) {
        case 'a':
            a++;
            break;
        case 'b':
            b++;
            break;
        case 'c':
            c++;
            break;
        }
    }

    auto max = std::max({a, b, c});
    auto min = std::min({a, b, c});

    if (max - min >= 2) {
        std::cout << "NO" << std::endl;
    }
    else {
        std::cout << "YES" << std::endl;
    }

    return 0;
}
