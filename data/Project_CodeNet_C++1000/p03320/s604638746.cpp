// IO library
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>

// container library
#include <array>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

template <typename T, typename U>
using P = pair<T, U>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

using ll = long long;

#define DOUBLE(n) static_cast<double>(n)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define NREP(i, n) FOR(i, 1, n + 1)
// Usual REP runs from 0 to n-1 (R: n-1 to 0)
// Natural REP runs from 1 to n (R: n to 1)

/* ---------- ここまでマクロ ----------*/

// bのn乗を再帰的に求める
ll mypow(ll b, ll n) {
    return n == 0 ? 1 : b * mypow(b, n - 1);
}

// 桁和を求める(B問題を参照)
ll dsum(ll n) {
    ll ret = 0;
    while (n > 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

// n以上で最小のすぬけ数を求める
ll snuke(ll n) {
    GPQ<P<double, ll>> val;
    // 逆順priority_queue, 一番上が最小の要素
    // (g(m), m)

    ll dig = 0;
    // 9が連続する桁数

    while (mypow(10, dig) <= n) {
        NREP(i, 9) {
            ll v = n - n % mypow(10, dig + 1) + i * mypow(10, dig) - 1;
            // 下dig桁が9
            // 1つ上は1~9
            // それより上はnと一致

            if (v >= n) {
                val.push(make_pair(DOUBLE(v) / dsum(v), v));
            }
        }
        dig++;
    }
    
    dig--;
    NREP(i, 100) {
        ll v = i * mypow(10, dig) - 1;
        if (v >= n) {
            val.push(make_pair(DOUBLE(v) / dsum(v), v));
        }
    }

    auto ret = val.top();
    // g(m)とmが最小となる(g(m), m)の組

    return ret.second;
}


int main() {
    ll K;
    cin >> K;
    ll pre = 1;
    REP(_, K) {
        cout << pre << endl;
        pre = snuke(pre + 1);
    }
    return 0;
}