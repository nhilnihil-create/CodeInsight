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
const int IMF = 1'000'000'000; //1e9
const int MIL = -1;
const long long LIMF = 1'000'000'000'000'000'000; // 1e18
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
    int M, K; std::cin >> M >> K;
    if(K >= (1<<M)){
        std::cout << -1 << std::endl;
        return 0;
    }
    if(!M){
        std::cout << "0 0\n";
        return 0;
    }
    if(M == 1){
        if(K){
            std::cout << -1 << std::endl;
            return 0;
        }
        std::cout << "0 0 1 1\n";
        return 0;
    }
    std::vector<int> b;
    for(int i(0), i_len(1 << M); i < i_len; ++i){
        if(i == K) continue;
        b.push_back(i);
    }
    for(int i(0), i_len(b.size()); i < i_len; ++i){
        if(i) std::cout << " ";
        std::cout << b[i];
    }
    std::cout << " " << K;
    for(int i(b.size() - 1); i >= 0; --i){
        std::cout << " " << b[i];
    }
    std::cout << " " << K << std::endl;
    return 0;
}
