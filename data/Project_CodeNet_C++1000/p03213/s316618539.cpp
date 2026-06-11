// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
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

#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
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

#ifdef __GXX_EXPERIMENTAL_CXX0X__
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
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif


//#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define repB(i, z, n) for(int i = n - 1; i >= z; i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
#define PI 3.14159265358979
//const int64_t INF = 1LL << 60;
const int INF = 1 << 29;
const int64_t MOD = 1000000007;
//const int64_t INF = 998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
//#define P pair<int, int>
typedef pair<int, int> P;
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31,
        37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    vector<int> num(101, 0);
    if (N <= 9){
        cout << 0 << endl;
        return 0;
    }
    rep(i, 2, N + 1){
        int p = i;
        rep(j, 0, 25){
            if (p == 1) break;
            if (p % prime.at(j) == 0){
                p /= prime.at(j);
                num.at(prime.at(j))++;
                j--;
            }
        }
    }
    int count_2 = 0, count_4 = 0, count_14 = 0, count_24 = 0, count_74 = 0;
    rep(i, 0, 101){
        //cout << i << " " << num.at(i) << endl;
        if (num.at(i) >= 2) count_2++;
        if (num.at(i) >= 4) count_4++;
        if (num.at(i) >= 14) count_14++;
        if (num.at(i) >= 24) count_24++;
        if (num.at(i) >= 74) count_74++;
    }
    //cout << count_2 << " " << count_4 << " " << count_14 << " " << count_24 << endl;
    int ans = count_24 * (count_2 - 1) + count_14 * (count_4 - 1) + count_4 * (count_4 - 1) * (count_2 - 2) / 2 + count_74;
    cout << ans << endl;
}
