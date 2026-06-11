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
    int N; std::cin >> N;
    std::string s;
    //cnt0: B...A, cnt1 B..., cnt ...A
    int cnt0(0), cnt1(0), cnt2(0);
    int ans(0);
    for(int a(0); a < N; ++a){
        std::cin >> s;
        int n(s.length());
        for(int i(0), i_len(n-1); i < i_len; ++i){
            if(s[i] == 'A' && s[i+1] == 'B') ++ans;
        }
        if(s[0] == 'B'){
            if(s[n-1] == 'A') ++cnt0;
            else ++cnt1;
        }else if(s[n-1] == 'A') ++cnt2;
    }
    ans += std::min(cnt1, cnt2);
    if(cnt0){
        ans += cnt0;
        if(!(cnt1 + cnt2)) --ans;
    }
    std::cout << ans << std::endl;
    return 0;
}
