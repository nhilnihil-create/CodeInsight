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


int dfs(int v, std::vector<std::vector<int>>& G, std::vector<int>& d){
    int ret(v), a;
    for(int u: G[v]){
        if(d[u] != INF) continue;
        d[u] = d[v] + 1;
        a = dfs(u, G, d);
        if(d[a] > d[ret]) ret = a;
    }
    return ret;
}


int main(){
    std::string s; std::cin >> s;
    int l(0), r(s.length()-1), cnt(0);
    while(l < r){
        if(s[l] == s[r]){
            ++l; --r;
        }else{
            if(s[l] == 'x') ++l;
            else if(s[r] == 'x') --r;
            else{
                std::cout << -1 << std::endl;
                return 0;
            }
            ++cnt;
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
