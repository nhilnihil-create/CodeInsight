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
    std::vector<int> a(M), b(M);
    std::vector<std::vector<bool>> G(N, std::vector<bool>(N, false));
    for(int i(0); i < M; ++i){
        std::cin >> a[i] >> b[i];
        --a[i]; --b[i];
        G[a[i]][b[i]] = G[b[i]][a[i]] = true;
    }
    int cnt(0);
    for(int i(0); i < M; ++i){
        std::vector<bool> visited(N, false);
        G[a[i]][b[i]] = G[b[i]][a[i]] = false;
        std::queue<int> que;
        visited[0] = true;
        que.push(0);
        while(!que.empty()){
            int e(que.front()); que.pop();
            for(int nxt(0); nxt < N; ++nxt){
                if(e == nxt) continue;
                if(!G[e][nxt]) continue;
                if(visited[nxt]) continue;
                visited[nxt] = true;
                que.push(nxt);
            }
        }
        bool ng(false);
        for(int i(0); i < N; ++i){
            if(!visited[i]){
                ng = true; break;
            }
        }
        if(ng) ++cnt;
        G[a[i]][b[i]] = G[b[i]][a[i]] = true;
    }
    std::cout << cnt << std::endl;
    return 0;
}
