#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <chrono>
#include <random>
#include <unordered_map>
#include <cassert>
#pragma GCC optimize("O3")
#pragma comment(linker, "STACK:36777216")
using namespace std;
using i64 = int64_t;
constexpr i64 MOD = 1e9 + 7;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
using vi = vector<i64>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ii = pair<i64, i64>;

int main() {
    string s;
    cin >> s;
    cout << s.substr(0, s.size() - 8) << endl;
}
