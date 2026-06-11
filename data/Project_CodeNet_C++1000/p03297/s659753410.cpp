//#pragma gcc optimize("Ofast,no-stack-protector,tune=native")
//#pragma gcc optimize("sse,sse2,sse3,sse4,ssse3")
//#pragma gcc optimize("O3")
//#pragma gcc optimize("abm,mmx,avx,avx2,fast-math,section-anchors")
//#pragma GCC optimize("Ofast,no-stack-protector,delete-null-pointer-check")
//#pragma GCC target("tune=native")
//#pragma GCC diagnostic error "-std=c++11"
//#pragma GCC target("avx")
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("inline")
//#pragma GCC optimize("-fgcse")
//#pragma GCC optimize("-fgcse-lm")
//#pragma GCC optimize("-fipa-sra")
//#pragma GCC optimize("-ftree-pre")
//#pragma GCC optimize("-ftree-vrp")
//#pragma GCC optimize("-fpeephole2")
//#pragma GCC optimize("-ffast-math")
//#pragma GCC optimize("-fsched-spec")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-falign-jumps")
//#pragma GCC optimize("-falign-loops")
//#pragma GCC optimize("-falign-labels")
//#pragma GCC optimize("-fdevirtualize")
//#pragma GCC optimize("-fcaller-saves")
//#pragma GCC optimize("-fcrossjumping")
//#pragma GCC optimize("-fthread-jumps")
//#pragma GCC optimize("-funroll-loops")
//#pragma GCC optimize("-fwhole-program")
//#pragma GCC optimize("-freorder-blocks")
//#pragma GCC optimize("-fschedule-insns")
//#pragma GCC optimize("inline-functions")
//#pragma GCC optimize("-ftree-tail-merge")
//#pragma GCC optimize("-fschedule-insns2")
//#pragma GCC optimize("-fstrict-aliasing")
//#pragma GCC optimize("-fstrict-overflow")
//#pragma GCC optimize("-falign-functions")
//#pragma GCC optimize("-fcse-skip-blocks")
//#pragma GCC optimize("-fcse-follow-jumps")
//#pragma GCC optimize("-fsched-interblock")
//#pragma GCC optimize("-fpartial-inlining")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("-freorder-functions")
//#pragma GCC optimize("-findirect-inlining")
//#pragma GCC optimize("-fhoist-adjacent-loads")
//#pragma GCC optimize("-frerun-cse-after-loop")
//#pragma GCC optimize("inline-small-functions")
//#pragma GCC optimize("-finline-small-functions")
//#pragma GCC optimize("-ftree-switch-conversion")
//#pragma GCC optimize("-foptimize-sibling-calls")
//#pragma GCC optimize("-fexpensive-optimizations")
//#pragma GCC optimize("-funsafe-loop-optimizations")
//#pragma GCC optimize("inline-functions-called-once")
//#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("avx2, O3")

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <deque>
#include <map>
#include <fstream>
#include <utility>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <random>
#include <math.h>
#include <cassert>
#include <bitset>
#include <chrono>
#include <sstream>
#include <array>

using namespace std;

#define DEBUG_VIVOD " SHTO-TO POSHLO NE TAK\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define pf push_front
#define _USE_MATH_DEFINES
#define filin(x) freopen(x, "r", stdin)
#define filout(x) freopen(x, "w", stdout)
#define deq deque
#define vec vector
#define umap unordered_map
#define uset unordered_set
#define nan nullptr
#define rtn(x) {return x;}
#define putin cin
#define putout cout


//typedef long long ll;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned long long ui;

#define INF 1e9
mt19937 prof_rand(time(0));
#define rand() prof_rand()

//signed main() {
//    vector<ll> ar(7);
//    for (auto& it : ar) putin >> it;
//    ll ans = (ar[0] - (ar[0] % 2ll)) * 2;
//    ar[0] = ar[0] % 2ll;
//    ans += ar[1] * 2;
//    if (ar[0] == 1 && (ar[3] % 2 == 1 || ar[4] % 2 == 1)) {
//        ar[3] -= 1;
//        ar[4] -= 1;
//        ar[0] -= 1;
//        ans += 6;
//    }
//    ans += (ar[3] - (ar[3] % 2ll)) * 2;
//    ans += (ar[4] - (ar[4] % 2ll)) * 2;
//    putout << ans / 2;
//}

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

bool check2(ll a, ll b, ll c) {
    if (b - a + 1 >= c || a % c == 0 || a % c > b % c) return true;
    return false;
}

bool check(ll A, ll B, ll C, ll D, ll E) {
    ll kek = gcd(A, C);
    ll l = (C + (D - B)) % C, r = (C + (E - B)) % C;
    vector<pair<ll, ll>> keks;
    if (r < l) {
        keks.pb({0, r});
        keks.pb({l, C - 1});
    } else keks.pb({l, r});
    bool ok = false;
    for (auto& it : keks) ok |= check2(it.first, it.second, kek);
    return !ok;
}

signed main() {
    ll t; putin >> t;
    while (t--) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        cout << (
                 (a >= b && d >= b)
                 ? (
                    c >= b || c + 1 == b || check(d % b, a % b, b, c + 1, b - 1)
                    ? "Yes\n"
                    : "No\n"
                    )
                 : "No\n"
                 );
    }
}
