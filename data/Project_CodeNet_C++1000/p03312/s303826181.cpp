#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
#include <cassert>
#include <random>
#include <time.h>
//#include <boost/multiprecision/cpp_int.hpp>



using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const double EPS = 1e-10;
long long const MOD = 1000000007;

long long mod_pow(long long x, long long n) {
    long long res = 1;
    for (int i = 0;i < 60; i++) {
        if (n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

template<typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

void fastInput() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

vector<Int> left_sum;
vector<Int> right_sum;

int main(void) {
    int N; cin >> N;
    vector<Int> A(N+5);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    left_sum = vector<Int> (N+1);
    right_sum = vector<Int> (N+1);
    for (int i = 1; i <= N; i++) {
        left_sum[i] = A[i];
        left_sum[i] += left_sum[i-1];
    }
    for (int i = 1; i <= N; i++) {
        right_sum[i] = A[N+1-i];
        right_sum[i] += right_sum[i-1];
    }

    Int INF = 1e16;
    Int ans = INF;
    for (int i = 2; i <= N-2; i++) {
        int P = (int)(lower_bound(left_sum.begin(), left_sum.end(), left_sum[i]/2) - left_sum.begin());
        int S = (int)(lower_bound(right_sum.begin(), right_sum.end(), right_sum[N-i]/2) - right_sum.begin());

        for (int j = P-1; j <= P+1; j++) {
            for (int k = S-1; k <= S+1; k++) {
                if (j <= 0 || i - j <= 0 || k <= 0 || N-i - k <= 0) continue;
                Int tmp = max({left_sum[j], left_sum[i] - left_sum[j], right_sum[k], right_sum[N-i] - right_sum[k]}) - min({left_sum[j], left_sum[i] - left_sum[j], right_sum[k], right_sum[N-i] - right_sum[k]});
                ans = min(tmp, ans);
            }
        }
    }
    cout << ans << endl;
}