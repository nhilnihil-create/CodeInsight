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


int gcd(int a, int b){
    if(!b) return a;
    if(a % b) return gcd(b, a % b);
    return b;
}

int main(){
    int N, M, Q; std::cin >> N >> M >> Q;
    // a[i][j] 区間がi<=x<=jの電車
    std::vector<std::vector<int>> a(N+1, std::vector<int>(N+1, 0)),
                                  s(N+1, std::vector<int>(N+1, 0));
    {
        int L, R; 
        for(int i(0); i < M; ++i){
            std::cin >> L >> R;
            ++a[L][R];
        }
    }
    for(int i(0); i < N; ++i){
        for(int j(0); j < N; ++j){
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i+1][j+1];
        }
    }
    {
        int l, r;
        for(int i(0); i < Q; ++i){
            std::cin >> l >> r;
            std::cout << s[r][r] + s[l-1][l-1] - s[l-1][r] - s[r][l-1] << "\n";
        }
    }
    return 0;
}
