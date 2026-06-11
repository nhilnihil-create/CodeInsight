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




bool check(int lt, int mid, int rt, std::string &lcond, std::string &cond, std::string & rcond){
    //true: 左側
    if((mid - lt) % 2){
        if(lcond == cond) return true;
        return false;
    }else{
        if(lcond == cond) return false;
        else true;
    }
}

int main(){
    int N; std::cin >> N;
    int lt(0), rt(N-1), mid;
    std::string lcond, rcond, cond;
    std::cout << lt << std::endl;
    std::cin >> lcond;
    if(lcond == "Vacant") return 0;
    std::cout << rt << std::endl;
    std::cin >> rcond;
    if(rcond == "Vacant") return 0;
    for(int j(0); j < 18; ++j){
        mid = (lt + rt) / 2;
        std::cout << mid << std::endl;
        std::cin >> cond;
        if(cond == "Vacant") return 0;
        if(check(lt, mid, rt, lcond, cond, rcond)){
            rt = mid; rcond = cond;
        }else{
            lt = mid; lcond = cond;
        }
    }
    return 0;
}
