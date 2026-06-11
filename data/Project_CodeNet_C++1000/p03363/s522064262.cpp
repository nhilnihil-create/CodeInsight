#define _USE_MATH_DEFINES
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <cmath>
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

const int MOD = 1000000007; 
const int INF = 1000000000; //1e9
const int NIL = -1;
const long long LINF = 1000000000000000000; // 1e18
const double EPS = 1E-10;

template<class T, class S>
bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S>
bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}




int main(){
    int N; std::cin >> N;
    long long prv(0);
    std::map<long long, long long> mp;
    mp[0] = 1;
    {
        int A;
        for(int i(0); i < N; ++i){
            std::cin >> A;
            prv += A;
            ++mp[prv];
        }
    }
    long long ans(0);
    {
        long long num;
        for(auto itr(mp.begin()); itr != mp.end(); ++itr){
            num = itr->second;
            ans += num*(num-1) / 2;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
