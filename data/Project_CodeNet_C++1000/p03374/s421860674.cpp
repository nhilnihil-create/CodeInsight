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

vector<Int> X;
vector<Int> V;
vector<Int> left_round;
vector<Int> left_max;
vector<Int> right_round;
vector<Int> right_max;


int main(void) {
    int N;
    Int C;
    cin >> N >> C;
    X.resize(N+2);
    V.resize(N+2);
    left_round.resize(N+2);
    left_max.resize(N+2);
    right_round.resize(N+2);
    right_max.resize(N+2);

    X[0] = 0;
    V[0] = 0;
    X[N+1] = C;
    V[N+1] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> V[i];
    }

    for (int i = 1; i <= N; i++) {
        right_round[i] = right_round[i-1] + V[i] - (X[i] - X[i-1]);
        right_max[i] = right_round[i];
        right_max[i] = max(right_max[i-1], right_max[i]);
    }
    for (int i = N; 1 <= i; i--) {
        left_round[i] = left_round[i+1] + V[i] - (X[i+1] - X[i]);
        left_max[i] = left_round[i];
        left_max[i] = max(left_max[i+1], left_max[i]);
    }

    Int ans = 0;
    // right-first
    for (int i = 0; i <= N; i++) {
        Int sum = right_round[i] - X[i];
        sum += left_max[i+1];
        ans = max(sum, ans);
        ans = max(right_round[i], ans);
    }
    // left-first
    for (int i = N; 1 <= i; i--) {
        Int sum = left_round[i] - (C - X[i]);
        sum += right_max[i-1];
        ans = max(sum, ans);
        ans = max(left_round[i], ans);
    }
    cout << ans << endl;
}