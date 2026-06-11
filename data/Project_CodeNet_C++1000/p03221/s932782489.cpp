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
    int N, M; std::cin >> N >> M;
    std::vector<int> P(M), Y(M);
    std::vector<std::map<int, int>> mp(N);

    for(int i(0); i < M; ++i){
        std::cin >> P[i] >> Y[i];
        --P[i];
        mp[P[i]][Y[i]] = 1;
    }
    for(int i(0); i < N; ++i){
        int j(1);
        for(auto &x: mp[i]){
            x.second = j;
            ++j;
        }
    }
    for(int i(0); i < M; ++i){
        int v(P[i]);
        std::cout << std::setfill('0');
        std::cout << std::setw(6) << v + 1;

        std::cout << std::setw(6) << mp[v][Y[i]] << std::endl;
    }
    return 0;
}
