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
#include <random>
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
    int N, K; std::cin >> N >> K;
    std::vector<int> V(N);
    for(int i(0); i < N; ++i) std::cin >> V[i];
    int M(std::min(N, K)), ans(0);
    for(int i(0); i <= M; ++i){
        int sumL(0);
        std::vector<int> dqL;
        for(int ii(0); ii < i; ++ii){
            sumL += V[ii];
            dqL.emplace_back(V[ii]);
        }
        for(int j(0); i+j <= M; ++j){
            int sum(sumL);
            std::vector<int> dq(dqL);
            for(int jj(0); jj < j; ++jj){
                sum += V[N-jj-1];
                dq.emplace_back(V[N-jj-1]);
            }
            std::sort(std::begin(dq), std::end(dq));
            for(int k(0); i+j+k < K; ++k){
                if(k >= dq.size()) break;
                if(dq[k] >= 0) break;
                sum -= dq[k];
            }
            chmax(ans, sum);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
