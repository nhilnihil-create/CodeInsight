#define _USE_MATH_DEFIMES
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const int MOD = 1'000'000'007;
const int INF = 1'000'000'000; //1e9
const int NIL = -1;
const long long LINF = 1'000'000'000'000'000'000; // 1e18
const long double EPS = 1E-10;

template<class T, class S> inline bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S> inline bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}





long long xorValue(long long x, std::vector<long long> &A,
                   std::unordered_map<long long, long long> &mp){
    if(mp.find(x) != std::end(mp)) return mp[x];
    long long ret(0);
    for(auto a: A){
        ret += (a ^ x);
    }
    return mp[x] = ret;
}

int main(){
    int N; std::cin >> N;
    long long K; std::cin >> K;
    std::vector<long long> A(N);
    for(int i(0); i < N; ++i) std::cin >> A[i];
    //10^12 < 2^40
    std::vector<long long> dp0(41), dp1(41);
    std::unordered_map<long long, long long> mp;
    for(int i(39); i >= 0; --i){
        if(xorValue(dp0[i+1], A, mp) >= xorValue(dp1[i+1], A, mp)){
            dp0[i] = dp0[i+1];
        }else{
            dp0[i] = dp1[i+1];
        }

        dp1[i] = dp0[i];
        long long a(dp0[i+1] + (1LL<<i));
        if(a <= K && xorValue(dp1[i], A, mp) < xorValue(a, A, mp)){
            dp1[i] = a;
        }
        a = dp1[i+1] + (1LL<<i);
        if(a <= K && xorValue(dp1[i], A, mp) < xorValue(a, A, mp)){
            dp1[i] = a;
        }
    }
    std::cout << std::max(xorValue(dp0[0], A, mp), xorValue(dp1[0], A, mp)) << std::endl;
    return 0;
}
