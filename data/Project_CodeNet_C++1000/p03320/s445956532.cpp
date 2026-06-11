#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long int LL;

LL K;
LL MAXV = 1ll << 60;

LL digit(LL v) {
    LL ret = 0;
    while (v > 0) {
        ret += v % 10;
        v /= 10;
    }
    return ret;
}

bool cmp(LL a, LL b) {
    if (a * digit(b) != b * digit(a))
        return a * digit(b) < b * digit(a);
    return a < b;
}

LL get(LL v) {
    vector <LL> tmp;
    LL a = 10, b = 9, t = v;
    tmp.push_back(v);
    while (t > 0) {
        t /= 10;
        tmp.push_back(v - v % a + b);
        a *= 10;
        b = b * 10 + 9;
    }
    sort(tmp.begin(), tmp.end(), cmp);
    //printf("%lld: %lld, len=%d\n", v, tmp[0], (int)tmp.size());
    return tmp[0];
}

int main() {
    scanf("%lld",&K);
    LL cur = 0;
    while (K--) {
        cur = get(cur+1);
        printf("%lld\n",cur);
    }
}










