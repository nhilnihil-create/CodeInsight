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
    int N, A, B; std::cin >> N;
    std::vector<int> AB(N);
    long long sum(0);
    for(int i(0); i < N; ++i){
        std::cin >> A >> B;
        sum -= B;
        AB[i] = A + B;
    }
    std::sort(AB.rbegin(), AB.rend());
    for(int i(0); i < N; i += 2)
        sum += AB[i];
    std::cout << sum << std::endl;
    return 0;
}
