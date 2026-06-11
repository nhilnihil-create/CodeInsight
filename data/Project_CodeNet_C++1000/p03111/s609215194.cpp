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

int A, B, C;
int dfs(int cur, int a, int b, int c, std::vector<int>& l){
    int lim(l.size());
    if(cur == lim)
        return ((std::min({a, b, c})) ? 
                 std::abs(a-A)+std::abs(b-B)+std::abs(c-C)-30 : INF);

    int ret0(dfs(cur+1, a,        b,        c,        l));
    int ret1(dfs(cur+1, a+l[cur], b,        c,        l) + 10);
    int ret2(dfs(cur+1, a,        b+l[cur], c,        l) + 10);
    int ret3(dfs(cur+1, a,        b,        c+l[cur], l) + 10);
    return std::min({ret0, ret1, ret2, ret3});
}
 
 
int main(){
    int N; std::cin >> N >> A >> B >> C;
    std::vector<int> l(N);
    for(int i(0); i < N; ++i) std::cin >> l[i];
    std::cout << dfs(0, 0, 0, 0, l) << std::endl;
    return 0;
}
