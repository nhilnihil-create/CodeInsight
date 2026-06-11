#define _USE_MATH_DEFINES
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






int main(){
    int A, B, Q; std::cin >> A >> B >> Q;
    std::vector<long long> s(A+2), t(B+2);
    s[0] = t[0] = -LINF;
    s[A+1] = t[B+1] = LINF;
    for(int i(0); i < A; ++i) std::cin >> s[i+1];
    for(int i(0); i < B; ++i) std::cin >> t[i+1];
    long long x;
    for(int q(0); q < Q; ++q){
        std::cin >> x;
        auto its(std::upper_bound(std::begin(s), std::end(s), x));
        auto itt(std::upper_bound(std::begin(t), std::end(t), x));
        std::vector<long long> a{*(its-1), *its}, b{*(itt-1), *itt};
        long long ans(LINF);
        for(int i(0); i < 2; ++i){
            for(int j(0); j < 2; ++j){
                chmin(ans,
                      std::min(std::abs(a[i]-x), std::abs(b[j]-x)) 
                       + std::abs(a[i]-b[j]));
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}
