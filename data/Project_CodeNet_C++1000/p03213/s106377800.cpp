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



int morethan(int a, std::vector<int> &cnt){
    int c(0);
    for(int i(0), i_len(cnt.size()); i < i_len; ++i){
        if(cnt[i] >= a) ++c;
    }
    return c;
}

int main(){
    int N; std::cin >> N;
    std::vector<int> cnt;
    std::vector<bool> prime(N+1, true);
    prime[0] = prime[1] = false;
    for(int i(2); i <= N; ++i){
        if(!prime[i]) continue;
        for(int j(i*2); j <= N; j += i){
            prime[j] = false;
        }
        int c(0);
        for(int j(i); j <= N; j *= i){
            c += N / j;
        }
        cnt.push_back(c);
    }
    int ans(0);
    ans += morethan(75-1, cnt);
    ans += morethan(25-1, cnt) * (morethan(3-1, cnt) - 1);
    ans += morethan(15-1, cnt) * (morethan(5-1, cnt) - 1);
    ans += morethan(5-1, cnt) * (morethan(5-1, cnt) - 1) / 2 * (morethan(3-1, cnt) - 2);
    std::cout << ans << std::endl;
    return 0;
}
